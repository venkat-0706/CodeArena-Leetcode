class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int res =-1, ans = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                res = i;
                break;
            }
        }
        return {ans,res};
    }
};