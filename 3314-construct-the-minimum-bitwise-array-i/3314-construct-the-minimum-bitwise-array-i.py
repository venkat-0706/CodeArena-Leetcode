class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            if num & 1:
                res.append(num & ~(((num + 1) & ~num) >> 1))
            else:
                res.append(-1)
        return res

        