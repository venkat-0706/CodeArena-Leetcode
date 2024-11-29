using info = tuple<int, short, short>; // (time, i, j)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(short i, short j, short n, short m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0]>1 && grid[0][1]>1)  return -1;// edge case
    
        short n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<info, vector<info>, greater<info>> pq;

        // Start at (0, 0) with time=0 
        pq.emplace(0, 0, 0);
        time[0][0] = 0;
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
        //    cout<<" t="<<int(t)<<" i="<<int(i)<<" j="<<int(j)<<endl;
            // reach the destination
            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;

                // minimum time to reach (r, s)
                int w=((grid[r][s]-t)&1)?0:1;
                int nextTime = max(t+1, grid[r][s]+w); // backward if neccessary

                // update if this path having quicker time
                if (nextTime < time[r][s]) {
                    time[r][s] = nextTime;
                    pq.emplace(nextTime, r, s);
                }
            }
        }

        return -1; // never reach
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();