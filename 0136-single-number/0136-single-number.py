class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        for i in nums:
            count ^= i
        return count
        