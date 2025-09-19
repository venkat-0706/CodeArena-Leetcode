class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        count = 0
        for i in range(n):
            if nums[i]!=0:
                nums[i],nums[count] = nums[count], nums[i]
                count+=1