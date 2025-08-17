class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        res = 0 
        n = len(nums)
        for i in range(32):
            count = 0
            for num in nums:
                if(num>>i)&1:
                    count += 1
            ans = n - count
            res += ans * count
        return res
            
        