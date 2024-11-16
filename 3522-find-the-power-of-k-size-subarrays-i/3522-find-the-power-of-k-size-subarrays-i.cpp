class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; ++i) {
            bool is_valid = true;
            int max_element = nums[i];

            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] + 1 != nums[j + 1]) {
                    is_valid = false;
                    break;
                }
                max_element = max(max_element, nums[j]);
            }

            if (is_valid) {
                result.push_back(max(max_element, nums[i + k - 1]));
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};