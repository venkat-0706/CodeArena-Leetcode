class Solution:
    def decompose(self, nums: List[int]) -> List[Tuple[int, int, int]]:
        n = len(nums)
        subarrays: List[Tuple[int, int, int]] = []

        l = 0
        s = nums[0]

        for i in range(1, n):
            # If we fail strict decreasing at boundary i-1 -> i, end the current subarray.
            if nums[i - 1] <= nums[i]:
                subarrays.append((l, i - 1, s))
                l = i
                s = 0
            s += nums[i]

        # last subarray
        subarrays.append((l, n - 1, s))
        return subarrays

    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)

        maxEndingAt = [0] * n
        for i in range(n):
            maxEndingAt[i] = nums[i]
            if i > 0 and nums[i - 1] < nums[i]:
                if maxEndingAt[i - 1] > 0:
                    maxEndingAt[i] += maxEndingAt[i - 1]

        maxStartingAt = [0] * n
        for i in range(n - 1, -1, -1):
            maxStartingAt[i] = nums[i]
            if i < n - 1 and nums[i] < nums[i + 1]:
                if maxStartingAt[i + 1] > 0:
                    maxStartingAt[i] += maxStartingAt[i + 1]

        PQS = self.decompose(nums)
        ans = -10**30  
        for (p, q, s) in PQS:
            if (p > 0 and nums[p - 1] < nums[p] and
                q < n - 1 and nums[q] < nums[q + 1] and
                p < q):
                cand = maxEndingAt[p - 1] + s + maxStartingAt[q + 1]
                if cand > ans:
                    ans = cand

        return ans