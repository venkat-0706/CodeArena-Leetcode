class Solution:
    def maxArea(self, nums: List[int]) -> int:
        i,j = 0, len(nums)-1
        res = 0
        while i<j:
            res = max(res,(j-i)*min(nums[i],nums[j]))
            if nums[i]<nums[j]:
                i+=1
            else:
                j-=1
        return res

