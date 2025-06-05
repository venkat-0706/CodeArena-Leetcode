class Solution {
public:
    void fun(int st, vector<int>&nums, vector<int>&v1,vector<vector<int>>&v){
        v.push_back(v1);
        for(int i=st;i<nums.size();i++){
            v1.push_back(nums[i]);
            fun(i+1,nums,v1,v);
            v1.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        vector<int>v1;
        fun(0,nums,v1,v);
        return v;        
    }
};