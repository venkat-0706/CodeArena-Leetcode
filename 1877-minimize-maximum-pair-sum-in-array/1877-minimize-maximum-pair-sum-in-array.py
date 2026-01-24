class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        s , e = 0 , len(nums)-1
        max_pair = 0 
        while s <= e:
            pair = nums[s] + nums[e]
            max_pair = max(max_pair , pair)
            s += 1
            e -= 1
        return max_pair
        