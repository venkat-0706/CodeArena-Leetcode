class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
      int n=events.size();
      sort(events.begin(),events.end()); 
      multiset<int> s;
      vector<int> maxi(n+1,INT_MIN);
      maxi[n]=0;
      s.insert(events[n-1][2]);
      maxi[n-1]=events[n-1][2];
      vector<int> next(n,-1);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      for(int i=0;i<n;i++)
      {
          while(pq.size())
          {
              auto pr=pq.top();
              if(pr.first<events[i][0])
              {
                  pq.pop();
                  next[pr.second]=i;
              }
              else
                break;
          }
          pq.push({events[i][1],i});
      }
      int ans=events[n-1][2];
      while(pq.size())
      {
        auto pr=pq.top();
        pq.pop();
        next[pr.second]=n;   
      }
      for(int i=n-2;i>=0;i--)
      {
          int index=next[i];
          ans=max(ans,events[i][2]+maxi[index]);
          maxi[i]=max(events[i][2],*(--s.end()));
          s.insert(events[i][2]);
      }
      return ans;
     
    }
};