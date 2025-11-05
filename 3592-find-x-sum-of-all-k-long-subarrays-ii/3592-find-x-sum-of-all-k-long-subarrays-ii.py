from sortedcontainers import SortedList

class Solution:
    def findXSum(self, A: List[int], K: int, X: int) -> List[int]:
        bot = SortedList()
        top = SortedList()
        count = Counter()
        cur_sum = 0

        def update(x, qty):
            nonlocal cur_sum

            if count[x]:
                try:
                    bot.remove([count[x], x])
                except:
                    top.remove([count[x], x])
                    cur_sum -= count[x] * x

            count[x] += qty
            if count[x]:
                bot.add([count[x], x])

        ans = []
        for i in range(len(A)):
            update(A[i], 1)
            if i >= K:
                update(A[i - K], -1)

            # rebalance
            while bot and len(top) < X:
                cx, x = bot.pop()
                cur_sum += cx * x
                top.add([cx, x])

            while bot and bot[-1] > top[0]:
                cx, x = bot.pop()
                cy, y = top.pop(0)
                cur_sum += cx * x - cy * y
                bot.add([cy, y])
                top.add([cx, x])

            if i >= K - 1:
                ans.append(cur_sum)

        return ans