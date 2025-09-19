class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        low , high = 0,n-1
        while low<high :
            mid = (low+high )// 2
            if nums[mid] < nums[mid+1]:
                low = mid+1
            else:
                high = mid
        return low
        