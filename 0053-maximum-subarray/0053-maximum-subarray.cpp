class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr_sum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            curr_sum = max(nums[i] + curr_sum, nums[i]);
            res = max(curr_sum , res);
        }
        return res;
    }
};