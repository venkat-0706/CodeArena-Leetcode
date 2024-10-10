
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        int n = nums.size();
        int subsetsCount = 1 << n; // 2^n subsets

        for (int i = 0; i < subsetsCount; ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            sets.push_back(subset);
        }
        return sets;
    }
};