from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return None
        count = Counter(nums)
        most_common = count.most_common(1)
        return most_common[0][0]
        
        