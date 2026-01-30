class Solution {
public:
    unordered_map<string,vector<pair<string,long long>>>dp;
    unordered_map<string,unordered_map<string,long long>>dis;
    vector<long long>memo;
    void find(string node){
        priority_queue<pair<long long,string>,vector<pair<long long,string>>,greater<pair<long long,string>>>pq;
        pq.push({0,node});
        dis[node][node]=0;
        while(pq.size()){
            auto [cost,u]=pq.top();
            pq.pop();
            for(auto &[v,w]:dp[u]){
                if(!dis[node].count(v) || dis[node][v]>w+cost){
                    dis[node][v]=w+cost;
                    pq.push({w+cost,v});
                }
            }
        }
    }
    long long dfs(string &s,string &t, int index, unordered_set<int>&lengths){
        if(index>=s.size()){
            return 0;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        long long ans=1e18;
        if(s[index]==t[index]){
            ans=dfs(s,t,index+1,lengths);
        }
        for(auto &len:lengths){
            string u=s.substr(index, len);
            string v=t.substr(index, len);

            if(dis.find(u)==dis.end() || dis[u].find(v)==dis[u].end()){
                continue;
            }
            ans=min(ans,dis[u][v]+dfs(s,t,index+len,lengths));
        }
        return memo[index]= ans;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=original.size();
        unordered_set<int>lengths;
        memo=vector<long long>(source.size()+1,-1);
        for(int i=0;i<n;i++){
            dp[original[i]].push_back({changed[i],cost[i]});
            lengths.insert(original[i].size());
        }
        for(int i=0;i<n;i++){
            find(original[i]);
        }
        long long result=dfs(source,target,0,lengths);
        return result>=1e18?-1:result;
    }
};