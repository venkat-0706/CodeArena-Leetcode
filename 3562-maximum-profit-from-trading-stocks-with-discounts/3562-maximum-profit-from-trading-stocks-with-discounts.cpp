

class Solution {
    vector<vector<int>> adj;
    pair<vector<int>,vector<int>> dp[161]; 
    bool solved[161]; 
    vector<int>  merge(vector<int> &a ,vector<int> &b){
        int bud = a.size(); 
        vector<int> res(bud,0);
         
        for (int i = 0 ; i < bud ; i ++ ) {
            for (int j = 0 ; i + j < bud ; j ++) {
                res[i + j] = max(res[i + j], a[i] + b[j]);
            }
        }
        return res; 
    }
    pair<vector<int>,vector<int>> solve(int node,vector<int> &present , vector<int> &future, int b) {
        if (solved[node]) {
            return dp[node]; 
        }
        solved[node] = true;
        vector<int> pt(b + 1, 0);
        vector<int> pnt(b + 1, 0);
        for (int c : adj[node]) {
            auto cres = solve(c,  present,future, b) ;
            pt = merge(pt, cres.first); 
            pnt = merge(pnt,cres.second);
        }
        vector<int> res1(b + 1, 0 ); 
        int cost1 = present[node]/2; 
        int cost2 = present[node]; 
        for (int i = 0 ; i <= b ; i ++) {
            res1[i] = pnt[i];
            if (i >= cost1) {
                res1[i] = max(res1[i], pt[i - cost1] + (future[node] - cost1)); 
            }
        }
        vector<int> res2(b + 1, 0); 
        for (int i = 0 ; i <= b ; i ++) {
            res2[i] = pnt[i];
            if (i >= cost2) {
                res2[i] = max(res2[i], pt[i - cost2] + (future[node] - cost2)); 
        }
    }
        return {res1,res2} ;
}
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        adj.resize(n);
        for (auto e : hierarchy ) {
            adj[--e[0]].push_back(--e[1]); 
        }
        auto res = solve(0,present, future, budget);  
        return (res.second)[budget]; 
    }
};