class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        if m<n:
             return self.maxDotProduct(nums2, nums1)
        dp = [float("-inf")] * (n+1)
        for i in range(m):
            prev=0
            for j in range(n):
                tmp=dp[j+1]
                dp[j+1]=max(prev+nums1[i]*nums2[j], nums1[i]*nums2[j], dp[j], dp[j+1])
                prev=tmp
        return dp[-1]