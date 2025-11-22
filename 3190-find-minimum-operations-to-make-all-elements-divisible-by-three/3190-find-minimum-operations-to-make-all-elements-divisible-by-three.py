class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        count = 0
        for i in range(len(nums)):
            if nums[i]%3!=0:
                count += 1
        return count
        