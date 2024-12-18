class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = prices[:]
        res = []
        for i in range(n):
            while res and prices[res[-1]] >= prices[i]:
                j = res.pop()
                ans[j] -= prices[i]
            res.append(i)
        return ans 
        