class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        n = len(nums)
        for i in range(n):
            if nums[i]==0: 
                for j in range(i+1,n):
                    if nums[j]!=0:
                        nums[i],nums[j] =nums[j],nums[i]
                        break