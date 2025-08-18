class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for (int i = 1; i < n; i++) {
            x ^= nums[i];
        }

        unsigned int ux = static_cast<unsigned int>(x);
        unsigned int k = ux & -ux;   

        int res = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & k) {
                res ^= nums[i];
            } else {
                ans ^= nums[i];
            }
        }

        return {res, ans};
    }
};
