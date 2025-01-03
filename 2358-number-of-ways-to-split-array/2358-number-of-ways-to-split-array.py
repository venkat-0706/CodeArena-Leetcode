class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        leftSideSum = 0
        rightSideSum = sum(nums)
        validSplits = 0
        
        for i in range(len(nums) - 1):
            leftSideSum += nums[i]
            rightSideSum -= nums[i]
            if leftSideSum >= rightSideSum:
                validSplits += 1
                
        return validSplits