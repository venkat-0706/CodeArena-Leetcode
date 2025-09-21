class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        seen = set(nums)
        i = 1 
        while i in seen:
            i += 1
        return i
        