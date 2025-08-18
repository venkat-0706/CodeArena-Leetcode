class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        x=nums[0]
        for i in range(1,len(nums)):
            x^=nums[i]
        k=(x&(~(x-1)))
        res,ans=0,0
        for i in range(len(nums)):
            if nums[i]&k!=0:
                res^=nums[i]
            else:
                ans^=nums[i]
        return [res,ans]
        