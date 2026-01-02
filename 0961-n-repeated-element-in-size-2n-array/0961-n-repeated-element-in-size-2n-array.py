class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        nums.sort()
        n= len(nums)
        for i in range(n+1):
            if nums[i] == nums[i-1]:
                return nums[i]

        
        