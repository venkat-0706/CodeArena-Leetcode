class Solution:
    def minCost(self, s, cost):
        res = max_cost = 0
        for i in range(len(s)):
            if i > 0 and s[i] != s[i - 1]:
                max_cost = 0
            res += min(max_cost, cost[i])
            max_cost = max(max_cost, cost[i])
        return res
        