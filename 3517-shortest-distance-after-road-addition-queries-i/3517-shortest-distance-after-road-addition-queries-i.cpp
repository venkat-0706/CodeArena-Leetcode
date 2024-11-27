class Solution {
public:
    
    
    vector <int> dijkstra(int V, vector<vector<int>> &adj, int S)
    {
        set<pair<int,int>> st; 

        vector<int> dist(V, 1e9); 
        
        st.insert({0, S}); 
        
        dist[S] = 0;
       
        while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            for(auto it : adj[node]) {
                int adjNode = it ; 
                int edgW = 1 ; 
                
                if( dis + edgW < dist[adjNode]) {
                    
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        
        return dist; 
    }

    
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans ;
        vector<vector<int>> adj (n) ;
        for ( int i = 0 ; i < n-1 ; i++ )
        {
            adj[i].push_back(i+1) ;
            // adj[i+1].push_back(i) ;
        }
        
        for ( auto it : queries )
        {
            adj[it[0]].push_back(it[1]) ;
            // adj[it[1]].push_back(it[0]) ;
            auto temp = dijkstra( n, adj, 0 ) ;
            ans.push_back(temp[n-1]) ;
        }
        return ans ;
    }
};