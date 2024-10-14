class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &i: nums)pq.push(i);
        long long ans = 0,x;
        while(k--){
            x = pq.top();
            pq.pop();
            ans += x;
            pq.push(ceil(x/3.0));
        }
        return ans;
    }
};