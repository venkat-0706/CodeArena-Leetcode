class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        ans , res = -1,-1
        for i in range(n):
            if nums[i] == target:
                ans = i
                break
        for i in range(n-1,-1,-1):
            if nums[i] == target:
                res = i
                break
        return (ans,res)
