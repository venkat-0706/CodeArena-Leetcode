class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        i = 0
        max_len = 0
        
        for j in range(len(nums)):
            while nums[j] > nums[i] * k:
                i += 1
            max_len = max(max_len, j - i + 1)
            
        return len(nums) - max_len