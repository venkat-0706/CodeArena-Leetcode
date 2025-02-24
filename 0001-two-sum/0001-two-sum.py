class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        temp = {}
        n = len(nums)
        for i in range(n):
            res = target -  nums[i]
            if res in temp:
                return [temp[res],i]
            temp[nums[i]] =  i
        return []
        

        