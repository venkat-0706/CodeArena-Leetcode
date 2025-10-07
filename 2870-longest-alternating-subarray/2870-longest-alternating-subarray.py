class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        res = ans = -1
        for i in range(1,n):
            if ans > 0 and nums[i]== nums[i-2]:
                ans += 1
            else:
                ans = 2 if nums[i] == nums[i-1] + 1 else -1
            res = max(res,ans)
        return res
        