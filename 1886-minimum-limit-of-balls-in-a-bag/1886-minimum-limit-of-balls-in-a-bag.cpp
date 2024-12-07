class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int mx = 0;
        for(auto &i: nums){
            mx = max(mx,i);
        }
        int mn = 1,mid,x,ans;
        while(mn<=mx){
            x = 0;
            mid = (mx-mn)/2+mn;
            for(auto &i: nums){
                if(i%mid){
                    x += i/mid;
                }else{
                    x += i/mid-1;
                }
            }
            if(x>k){
                mn = mid+1;
            }else{
                ans= mid;
                mx = mid-1;
            }
        }
        return ans;
    }
};