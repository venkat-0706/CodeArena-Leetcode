class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        for r1, c1, r2, c2 in queries:
            ans[r1][c1] += 1
            if r2 + 1 < n: ans[r2 + 1][c1] -= 1
            if c2 + 1 < n: ans[r1][c2 + 1] -= 1
            if r2 + 1 < n and c2 + 1 < n: ans[r2 + 1][c2 + 1] += 1
        for r in range(1, n):
            for c in range(n):
                ans[r][c] += ans[r - 1][c]
        for r in range(n):
            for c in range(1, n):
                ans[r][c] += ans[r][c - 1]
        return ans