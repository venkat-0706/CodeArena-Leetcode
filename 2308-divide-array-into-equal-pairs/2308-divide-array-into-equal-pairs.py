class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        n = len(nums)
        nums.sort()
        return all(nums[i] == nums[i+1] for i in range(0,n,2))

        