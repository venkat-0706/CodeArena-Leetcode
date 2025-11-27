class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long ans = -1e18;
        long long dp[k];
        for(int i = 0; i < k; i ++) dp[i] = 1e18;
        dp[0] = 0;
        for(int i = 1; i <= n; i ++){
            sum += nums[i-1];
            ans = max(ans, sum - dp[i % k]);
            dp[i % k] = min(dp[i % k], sum);
        }
        return ans;
    }
};