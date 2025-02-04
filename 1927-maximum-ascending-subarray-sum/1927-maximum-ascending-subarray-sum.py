class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)
        max_sum = 0
        curr_sum =  nums[0]
        for i in range(1,n):
            if nums[i] <= nums[i-1]:
                max_sum = max(max_sum, curr_sum)
                curr_sum = 0
            curr_sum += nums[i]
        return max(max_sum , curr_sum)

        