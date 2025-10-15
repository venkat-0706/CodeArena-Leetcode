class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        l = []
        start = 0
        for i in range(1,len(nums)):
            if nums[i] <= nums[i-1]:
                l.append(i-start)
                start = i
        if sum(l) < len(nums):
            l.append(len(nums) - sum(l))
        res = max(l) // 2
        for i in range(len(l)-1):
            res = max(res, min(l[i], l[i+1]))
        return res