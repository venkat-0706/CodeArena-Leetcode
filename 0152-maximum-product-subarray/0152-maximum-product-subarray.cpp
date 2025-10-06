#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr_max = nums[0];
        int curr_min = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = curr_max;
            curr_max = max({nums[i], nums[i] * curr_max, nums[i] * curr_min});
            curr_min = min({nums[i], nums[i] * temp, nums[i] * curr_min});
            res = max(res, curr_max);
        }
        return res;
    }
};
