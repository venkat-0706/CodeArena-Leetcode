class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            vector<int>arr;
            for(int i=0;i<nums.size()-1;i++){
                arr.push_back((nums[i]+nums[i+1])%10);
            }
            nums = arr;
        }
        return nums[0];

    }
};