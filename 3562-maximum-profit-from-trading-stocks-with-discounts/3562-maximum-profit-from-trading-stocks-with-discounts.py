from typing import List

class Solution:
    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        tree = [[] for _ in range(n)]
        for u, v in hierarchy:
            tree[u - 1].append(v - 1)

        dp = [[[0] * (budget + 1) for _ in range(2)] for _ in range(n)]
        self.dfs(0, present, future, tree, dp, budget)
        return max(dp[0][0])

    def dfs(self, u, present, future, tree, dp, budget):
        children = tree[u]
        child_dps = []
        for v in children:
            self.dfs(v, present, future, tree, dp, budget)
            child_dps.append((dp[v][0], dp[v][1]))

        for parentBought in range(2):
            price = present[u] // 2 if parentBought else present[u]
            profit = future[u] - price

            # Option 1: not buying u
            base = [0] * (budget + 1)
            for c0, _ in child_dps:
                next_base = [0] * (budget + 1)
                for b in range(budget + 1):
                    if base[b] == 0 and b != 0:
                        continue
                    for k in range(budget - b + 1):
                        next_base[b + k] = max(next_base[b + k], base[b] + c0[k])
                base = next_base

            curr = base[:]

            # Option 2: buying u
            if price <= budget:
                base = [0] * (budget + 1)
                for _, c1 in child_dps:
                    next_base = [0] * (budget + 1)
                    for b in range(budget + 1):
                        if base[b] == 0 and b != 0:
                            continue
                        for k in range(budget - b + 1):
                            next_base[b + k] = max(next_base[b + k], base[b] + c1[k])
                    base = next_base

                for b in range(price, budget + 1):
                    curr[b] = max(curr[b], base[b - price] + profit)

            dp[u][parentBought] = curr