class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for num in matrix:
            for i in num:
                if i == target:
                    return True
        return False
        