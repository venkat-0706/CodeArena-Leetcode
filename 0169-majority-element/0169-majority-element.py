class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        count = 0
        res = None
        for num in nums:
            if count == 0:
                res = num
            count += (1 if num == res else -1)
        if nums.count(res) > len(nums) // 2:
            return res
        return -1
