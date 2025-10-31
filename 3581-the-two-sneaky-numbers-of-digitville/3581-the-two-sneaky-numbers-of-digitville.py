from collections import Counter
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)-2
        res = []
        for i in range(len(nums)):
            while 0<= nums[i] < len(nums) and nums[nums[i]]!= nums[i]:
                j =  nums[i]
                nums[i],nums[j] = nums[j],nums[i]
        for i in range(len(nums)):
            if nums[i]!=i:
                res.append(nums[i])
            if len(res)==2:
                break
        return res

        