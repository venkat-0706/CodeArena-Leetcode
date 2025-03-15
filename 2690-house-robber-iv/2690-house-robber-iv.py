class Solution:
    def minCapability(self, nums, k):
        start, end = 1, max(nums)
        total  = len(nums)
        while start< end:
            mid = (start + end) // 2
            count = 0

            index = 0
            while index < total:
                if nums[index] <= mid:
                    count += 1
                    index += 2
                else:
                    index += 1

            if count >= k:
                end = mid
            else:
                start  = mid + 1

        return start