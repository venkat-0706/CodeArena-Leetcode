class Solution:
    def maxSubarraySumCircular(self, nums):
        curr_min = curr_max = min_sum = max_sum = total_sum = nums[0]
        
        for i in range(1, len(nums)):
            curr_max = max(nums[i], curr_max + nums[i])
            max_sum = max(max_sum, curr_max)

            curr_min = min(nums[i], curr_min + nums[i])
            min_sum = min(min_sum, curr_min)

            total_sum += nums[i]

        if min_sum == total_sum:
            return max_sum
        return max(max_sum, total_sum - min_sum)