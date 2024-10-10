class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> count = {{0, 0}, {1, 0}, {2, 0}};

        for (int num : nums) {
            count[num]++;
        }

        int idx = 0;
        for (int color = 0; color < 3; color++) {
            int freq = count[color];
            for (int j = 0; j < freq; j++) {
                nums[idx] = color;
                idx++;
            }
        }        
    }
};