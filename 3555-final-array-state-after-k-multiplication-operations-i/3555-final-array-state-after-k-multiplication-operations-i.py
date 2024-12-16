class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            x=nums.index(min(nums))
            nums[x]*=multiplier
        return nums