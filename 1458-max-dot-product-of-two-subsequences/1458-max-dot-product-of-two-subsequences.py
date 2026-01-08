class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        # Always make nums2 the smaller one for less memory
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        dp = [float('-inf')] * (n + 1)

        for i in range(m):
            prev = float('-inf')
            a = nums1[i]
            for j in range(n):
                b = nums2[j]
                curr = a * b

                temp = dp[j + 1]
                dp[j + 1] = max(
                    prev + curr,  # extend previous subsequence
                    curr,         # start new subsequence
                    dp[j + 1],    # skip nums1[i]
                    dp[j]         # skip nums2[j]
                )
                prev = temp

        return dp[n]
