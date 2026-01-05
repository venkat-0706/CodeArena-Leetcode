class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total = 0
        neg = 0
        min_abs = float('inf')

        for row in matrix:
            for v in row:
                if v < 0:
                    neg += 1
                    v = -v 
                total += v
                if v < min_abs:
                    min_abs = v

        if neg & 1:
            total -= 2 * min_abs
        return total
