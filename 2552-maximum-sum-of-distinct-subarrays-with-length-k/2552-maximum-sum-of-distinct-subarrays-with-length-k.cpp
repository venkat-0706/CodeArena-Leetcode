class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long start=0,cnt=0,ans=0;
        for(int i=0;i<n;i++){
            cnt+=nums[i];
            if(mp.find(nums[i])!=mp.end()){
                while(start<=mp[nums[i]]){
                    cnt-=nums[start];
                    mp.erase(nums[start]);
                    start++;
                }
                mp[nums[i]]=i;
            }
            mp[nums[i]]=i;
            if(i-start+1==k){
                ans=max(ans,cnt);
                cnt-=nums[start];
                mp.erase(nums[start]);
                start++;
            }
        }
        return ans;
    }
};