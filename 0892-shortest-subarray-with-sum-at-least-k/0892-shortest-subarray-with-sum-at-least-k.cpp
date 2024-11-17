class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1);
        
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        vector<int> q(n + 1);
        int l = 0, r = 0;
        int minLength = n + 1;
        
        for (int i = 0; i < sum.size(); i++) {
            while (r > l && sum[i] >= sum[q[l]] + k) {
                minLength = min(minLength, i - q[l++]);
            }
            
            while (r > l && sum[i] <= sum[q[r - 1]]) {
                r--;
            }
            
            q[r++] = i;
        }
        
        return minLength <= n ? minLength : -1;
    }
};