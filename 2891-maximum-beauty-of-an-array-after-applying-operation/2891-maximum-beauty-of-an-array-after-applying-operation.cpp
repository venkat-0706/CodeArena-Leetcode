class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        int maxx=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            while(s<i&&nums[s]+k<nums[i]-k){
                  s+=1;
            }
            maxx=max(maxx,i-s+1);
        }
        return maxx;
    }
};