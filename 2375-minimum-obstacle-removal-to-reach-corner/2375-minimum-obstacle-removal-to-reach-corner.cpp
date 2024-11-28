class Solution {
public:
    int m,n;
    bool check(int x,int y)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }
    int minimumObstacles(vector<vector<int>>& a) {
        
         this->m=a.size();
         this->n=a[0].size();
         vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
         dp[0][0]=0;
         vector<int> dir{0,1,0,-1,0};
         set<vector<int>> q;
         q.insert({0,0,0}); // {dis,x,y}

          // dijkstra 

          while(!q.empty())
          {
             vector<int> c=*(q.begin());
             q.erase(q.begin());
             int x=c[1];
             int y=c[2];
             for(int i=0;i<4;i++)
             {
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(check(nx,ny))
                {
                    int len=a[nx][ny];
                    if(dp[x][y]+len<dp[nx][ny])
                    {
                        q.erase({dp[nx][ny],nx,ny});
                        dp[nx][ny]=dp[x][y]+len;
                        q.insert({dp[nx][ny],nx,ny});
                    }
                }
             }


          }

          return dp[m-1][n-1];


    }
};