class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        n =  len(nums)
        nums.sort()
        ans =  nums[k-1] - nums[0]
        for i in range(0,n-k+1):
            ans = min(ans, nums[i+k-1]-nums[i])
        return ans

        