class Solution(object):
    def pacificAtlantic(self, heights):
        m, n = len(heights), len(heights[0])
        pacific = [[False for _ in range(n)] for _ in range(m)]
        atlantic = [[False for _ in range(n)] for _ in range(m)]

        for i in range(m):
            pacific[i][0] = True
            atlantic[i][n - 1] = True
        for j in range(n):
            pacific[0][j] = True
            atlantic[m - 1][j] = True

        updated = True

        while updated:
            updated = False
            for i in range(m):
                for j in range(n):
                    if not pacific[i][j]:
                        if i > 0 and pacific[i - 1][j] and heights[i][j] >= heights[i - 1][j]:
                            pacific[i][j] = True
                            updated = True
                        elif i < m - 1 and pacific[i + 1][j] and heights[i][j] >= heights[i + 1][j]:
                            pacific[i][j] = True
                            updated = True
                        elif j > 0 and pacific[i][j - 1] and heights[i][j] >= heights[i][j - 1]:
                            pacific[i][j] = True
                            updated = True
                        elif j < n - 1 and pacific[i][j + 1] and heights[i][j] >= heights[i][j + 1]:
                            pacific[i][j] = True
                            updated = True

                    if not atlantic[i][j]:
                        if i > 0 and atlantic[i - 1][j] and heights[i][j] >= heights[i - 1][j]:
                            atlantic[i][j] = True
                            updated = True
                        elif i < m - 1 and atlantic[i + 1][j] and heights[i][j] >= heights[i + 1][j]:
                            atlantic[i][j] = True
                            updated = True
                        elif j > 0 and atlantic[i][j - 1] and heights[i][j] >= heights[i][j - 1]:
                            atlantic[i][j] = True
                            updated = True
                        elif j < n - 1 and atlantic[i][j + 1] and heights[i][j] >= heights[i][j + 1]:
                            atlantic[i][j] = True
                            updated = True

        result = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])

        return result