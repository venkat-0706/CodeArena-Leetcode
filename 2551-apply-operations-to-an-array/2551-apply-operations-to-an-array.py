class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        zero = 0
        for i in range(n-1):
            if (i < n-1 and nums[i] == nums[i+1]):
                nums[i] *= 2
                nums[i+1] = 0
        for i in range(n):
            if nums[i] != 0:
                nums[zero],nums[i] = nums[i],nums[zero]
                zero += 1
                
        return nums
        