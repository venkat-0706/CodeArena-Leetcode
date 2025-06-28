class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
    int curr_sum = 0, max_sum = INT_MIN;
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < n; ++i) {
        curr_sum += nums[i];

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }

        if (curr_sum < 0) {
            curr_sum = 0;
            temp_start = i + 1;
        }
    }

    // Optional: Print or return the actual subarray from nums[start] to nums[end]
    return max_sum;
}
};