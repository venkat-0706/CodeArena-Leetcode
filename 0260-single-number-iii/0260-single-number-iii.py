class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        n=len(nums)
        x=nums[0]
        for i in range(1,n):
            x^=nums[i]
        k = (x&(~(x-1)))
        res,ans=0,0
        for i in range(n):
            if(nums[i]&k!=0):
                res^=nums[i]
            else:
                ans^=nums[i]
        return [res,ans]
        