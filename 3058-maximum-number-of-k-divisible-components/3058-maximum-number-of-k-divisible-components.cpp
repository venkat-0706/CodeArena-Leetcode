class Solution {
public:
    int ans=0;
    vector<vector<int>> adj;
    bitset<30001> visited=0;
    inline void build_adj(int n, vector<vector<int>>& edges, vector<int>& values)
    {
        for(auto& e: edges){
            int i=e[0], j=e[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    inline long long dfs(int i, vector<int>& values, int k){
        visited[i]=1;
        long long sum=values[i];
        for (int j: adj[i]){
            if (visited[j]) continue;
            sum+=dfs(j, values, k);
            sum%=k;
        }
        if (sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        adj.resize(n);
    
        build_adj(n, edges, values);

        dfs(0, values, k);

        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();