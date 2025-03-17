from collections import Counter
class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        count = Counter(nums)
        return all(count %2 == 0 for count in count.values())


        