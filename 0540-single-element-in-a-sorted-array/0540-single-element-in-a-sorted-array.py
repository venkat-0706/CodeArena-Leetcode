from collections import Counter
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            count ^= num
        return count
        