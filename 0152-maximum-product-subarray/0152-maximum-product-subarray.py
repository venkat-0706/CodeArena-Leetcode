class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        curr_max , curr_min = 1,1
        for num in nums:
            temp = curr_max *num
            curr_max = max(num*curr_max,  num*curr_min , num)
            curr_min = min(temp ,num*curr_min , num)
            res = max(res,curr_max)
        return res
        