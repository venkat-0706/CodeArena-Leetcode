class Solution {
public:

    bool haveSameSetBits(int a, int b) {
        return __builtin_popcount(a) == __builtin_popcount(b);
    }

    bool canSortArray(vector<int>& nums) {
        
        int N = nums.size(), times = nums.size();
        while (times--) {
            for (int i = 0; i < N - 1; i++) {
                if (haveSameSetBits(nums[i], nums[i + 1]) && nums[i + 1] < nums[i]) {
                    swap(nums[i], nums[i + 1]);
                }
            } 
        }

        return is_sorted(nums.begin(), nums.end());
    }
};