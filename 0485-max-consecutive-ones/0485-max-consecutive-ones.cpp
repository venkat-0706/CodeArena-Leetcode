class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0 ;
        int res= 0 ;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count= 0 ;
            } else{
                count++;
                res = max(count,res);
            }
        }
        return res;
    }
};