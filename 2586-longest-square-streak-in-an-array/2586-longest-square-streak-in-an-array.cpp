class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int>mp;
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int num: nums) {
            int _sqrt = sqrt(num);
            if(_sqrt*_sqrt == num && mp.find(_sqrt)!=mp.end()) {
                mp[num] = mp[_sqrt]+1;
                res = max(res, mp[num]);
            } else mp[num] = 1;
        }
        return res;
    }
};