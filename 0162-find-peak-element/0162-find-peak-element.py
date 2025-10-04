class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        l , r = 0,n-1
        while l<r:
            m = (l+r)//2
            if nums[m] < nums[m+1]:
                l=m+1
            else:
                r=m
        return l

        