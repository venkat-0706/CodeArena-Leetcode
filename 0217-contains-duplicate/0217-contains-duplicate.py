class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n = len(nums)
        arr = set(nums)
        if n != len(arr):
            return True
        else:
            return False


        