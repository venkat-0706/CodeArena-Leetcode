class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        n =  len(nums)
        count = 0
        res = 0 
        for i in range(n):
            if nums[i]==0:
                count =0
            else:
                count += 1
                res = max(count , res)
        return res
        