from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs[0])
        m = len(strs)
        dp = [1] * n

        for i in range(1, n):
            for j in range(i):
                ok = True
                for r in range(m):
                    if strs[r][j] > strs[r][i]:
                        ok = False
                        break
                if ok:
                    dp[i] = max(dp[i], dp[j] + 1)

        mx = 0
        for v in dp:
            mx = max(mx, v)
        return n - mx