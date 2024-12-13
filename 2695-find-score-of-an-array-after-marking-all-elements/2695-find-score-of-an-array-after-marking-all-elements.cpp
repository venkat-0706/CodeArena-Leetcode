class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();;
        if(n==1)return nums[0];
        long long int ans = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int i;
        for(i = 0; i < n; i++){
            pq.push({nums[i],i});
        }
        vector<int> v(n,true);
        vector<int> tmp;
        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();
            if(tmp[1]==0 && v[0]){
                ans += tmp[0];
                v[0] = v[1] = false;
            }else if(tmp[1]==n-1 && v[n-1]){
                ans += tmp[0];
                v[n-2] = v[n-1] = false;
            }else if(v[tmp[1]]){
                ans += tmp[0];
                v[tmp[1]-1] = v[tmp[1]] = v[tmp[1]+1] = false;
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};