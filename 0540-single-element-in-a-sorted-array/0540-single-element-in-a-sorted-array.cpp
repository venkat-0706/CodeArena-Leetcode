class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            count ^= nums[i];
        }
        return count;
    }
};