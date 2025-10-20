class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        count = 0
        for num in operations:
            if "--" in num:
                count -= 1
            else:
                count += 1
        return count
        