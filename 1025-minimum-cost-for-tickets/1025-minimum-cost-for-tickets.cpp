class Solution {
public:
    int fs(int index, unordered_set<int>& hehe, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (index > 365) return 0;  
        if (dp[index] != -1) return dp[index];  

        if (hehe.find(index) == hehe.end()) {
           
            return dp[index] = fs(index + 1, hehe, days, costs, dp);
        }

       
        int first = costs[0] + fs(index + 1, hehe, days, costs, dp);
        int second = costs[1] + fs(index + 7, hehe, days, costs, dp);
        int third = costs[2] + fs(index + 30, hehe, days, costs, dp);

      
        return dp[index] = min({first, second, third});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);  
        unordered_set<int> hehe(days.begin(), days.end());  
        return fs(1, hehe, days, costs, dp);
    }
};
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();