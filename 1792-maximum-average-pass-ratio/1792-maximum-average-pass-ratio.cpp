class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int exS) {
        priority_queue<pair<double, pair<double, double>>, 
        vector<pair<double, pair<double, double>>>> pq;

        for(int i=0; i<classes.size(); i++){
            double cr = (double)(classes[i][0]+1)/(double)(classes[i][1]+1)
                        -(double)classes[i][0]/(double)classes[i][1];
            pq.push({cr, {classes[i][0], classes[i][1]}});
        }
        while(exS--){
            pair<double, pair<double, double>> p=pq.top();
            pq.pop();
            double cr = (p.second.first+2)/(p.second.second+2)
                        -(p.second.first+1)/(p.second.second+1);
            pq.push({cr, {p.second.first+1, p.second.second+1}});
        }
        double ans=0;
        while(!pq.empty()){
            pair<double, pair<double, double>> p=pq.top();
            pq.pop();
            ans+=p.second.first/p.second.second;
        }
        return ans/classes.size();
    }
};