class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            bool Start = (i == 0);
            bool End = (i == n - 1);
            if ((Start || nums[i] != nums[i - 1]) && (End || nums[i] != nums[i + 1])) {
                return nums[i];
            }
        }
        return -1;
    }
};