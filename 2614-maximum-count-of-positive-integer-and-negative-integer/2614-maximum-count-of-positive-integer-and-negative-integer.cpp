class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0,neg =0;
        for(int num:nums){
            pos += num > 0;
            neg += num < 0;
        }
        return max(pos, neg);
    }
};