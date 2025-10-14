class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        knew = k - 1
        if knew == 0:
            return True
        for j in range(k + 1, len(nums)):
            if nums[j] > nums[j - 1] and nums[j - k] > nums[j - k - 1]:
                knew -= 1
            else:
                knew = k - 1
            if knew == 0:
                return True
        return False