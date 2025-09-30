from typing import List

class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1: 
            temp = []
            for i in range(len(nums) - 1):
                temp.append((nums[i] + nums[i + 1]) % 10)
            nums = temp
        return nums[0]
