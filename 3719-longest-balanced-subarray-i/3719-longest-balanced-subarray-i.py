class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0

        maxVal = max(nums)
        seen = [0] * (maxVal + 1)

        for i in range(n):
            A = [0, 0]

            for j in range(i, n):
                val = nums[j]
                if seen[val] != i + 1:
                    seen[val] = i + 1
                    A[val & 1] += 1

                if A[0] == A[1]:
                    res = max(res, j - i + 1)

        return res
