class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        index = 0
        for i in range(n):
            if nums[i] != val:
                nums[index] = nums[i]
                index = index + 1
        return index