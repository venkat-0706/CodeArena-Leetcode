class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
	    m, n, mod = len(grid), len(grid[0]), 10 ** 9 + 7
	    dp = [[[0] * k for _ in range(n)] for _ in range(m)]
	    dp[0][0][grid[0][0] % k] = 1
	    for i in range(m):
		    for j in range(n):
			    for s in range(k):
				    modded_sum = (s + grid[i][j]) % k
				    if j > 0: dp[i][j][modded_sum] += dp[i][j - 1][s]
				    if i > 0: dp[i][j][modded_sum] += dp[i - 1][j][s]
				    dp[i][j][modded_sum] %= mod
	    return dp[m - 1][n - 1][0]
        