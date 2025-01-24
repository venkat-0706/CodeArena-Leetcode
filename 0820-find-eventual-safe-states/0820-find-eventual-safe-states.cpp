class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safe(n, false), vis(n, false);
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!vis[i]) dfs(graph, vis, i, safe);
            if(safe[i]) ans.push_back(i); 
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int node, vector<bool>& safe){
        vis[node] = true;
        bool ret = true;
        for(auto nei : graph[node]){
            ret &= vis[nei] ? safe[nei] : dfs(graph, vis, nei, safe);
        }
        return safe[node] = ret;
    }
};