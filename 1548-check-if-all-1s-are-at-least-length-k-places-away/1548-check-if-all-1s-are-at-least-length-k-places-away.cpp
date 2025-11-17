class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int n = nums.size();
        int pre_index;
        bool f = true;

        for (int i = 0; i < n; i++) {
            if (f && nums[i] == 1) {
                f = false;
                pre_index = i;
                continue;
            }
            if (nums[i] == 1) {
                if (i - pre_index - 1 >= k)
                    pre_index = i;
                else
                    return false;
            }
        }

        return true;
    }
};