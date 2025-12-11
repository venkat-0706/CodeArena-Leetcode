class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minx(n + 1, n + 1);
        vector<int> maxx(n + 1, 0);
        vector<int> miny(n + 1, n + 1);
        vector<int> maxy(n + 1, 0);
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            minx[y] = min(minx[y], x);
            maxx[y] = max(maxx[y], x);
            miny[x] = min(miny[x], y);
            maxy[x] = max(maxy[x], y);
        }
        int ans = 0;
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            if(minx[y] < x && x < maxx[y] && miny[x] < y && y < maxy[x]){
                ans += 1;
            }
        }
        return ans;
    }
};