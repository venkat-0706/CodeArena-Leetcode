class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        h1 = set(nums1)
        h2 = set(nums2)
        for num in nums2:
            if num in h1:
                h1.remove(num)
                h2.discard(num)
        return [list(h1),list(h2)]

        