class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        max_len = 0
        n = len(nums)
        for i in range(n):
            count = 1
            for pos in range(i+1,n):
                if nums[pos] > nums[pos-1]:
                    count += 1
                else:
                    break
            max_len = max(max_len , count)
        for i in range(n):
            count = 1
            for pos in range(i+1,n):
                if nums[pos] < nums[pos-1]:
                    count += 1
                else:
                    break
            max_len = max(max_len , count)
        return max_len
            
        
        