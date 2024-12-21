class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        zero = 0
        for i in range(n):
            if nums[i] != 0 :
                nums[zero] = nums[i]
                zero += 1
        for i in range(zero,n):
            nums[i] = 0
        return nums