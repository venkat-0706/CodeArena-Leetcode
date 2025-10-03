class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for num in matrix:
            for n in num:
                if n == target:
                    return True
        return False
        