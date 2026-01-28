class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        dp = [[float(inf) for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = 0
                else:
                    if i > 0:
                        dp[i][j] = min(dp[i][j], dp[i-1][j])
                    if j > 0:
                        dp[i][j] = min(dp[i][j], dp[i][j-1])
                    dp[i][j] += grid[i][j]

        for kk in range(k):
            s = sorted((-grid[i][j], dp[i][j], i, j) for j in range(n) for i in range(m))
            dp_next = [[float(inf) for _ in range(n)] for _ in range(m)]
            cc = float(inf)
            for _, c, i, j in s:
                cc = min(cc, c)
                dp_next[i][j] = cc
                
            for i in range(m):
                for j in range(n):
                    if i == 0 and j == 0:
                        dp_next[i][j] = 0
                    else:
                        if i > 0:
                            dp_next[i][j] = min(dp_next[i][j], dp_next[i-1][j] + grid[i][j])
                        if j > 0:
                            dp_next[i][j] = min(dp_next[i][j], dp_next[i][j-1] + grid[i][j])
            dp = dp_next
        return dp[-1][-1]