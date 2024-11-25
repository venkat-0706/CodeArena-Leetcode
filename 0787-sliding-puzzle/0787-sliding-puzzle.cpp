class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        for (auto& r : board) {
            for (int n : r) {
                s += to_string(n);
            }
        }
        
        string g = "123450";
        
        vector<vector<int>> n = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        
        queue<pair<string, int>> q;
        unordered_set<string> v;
        
        q.push({s, 0});
        v.insert(s);
        
        while (!q.empty()) {
            auto [c, m] = q.front();
            q.pop();
            
            if (c == g) return m;
            
            int z = c.find('0');
            
            for (int x : n[z]) {
                string t = c;
                swap(t[z], t[x]);
                
                if (v.find(t) == v.end()) {
                    q.push({t, m + 1});
                    v.insert(t);
                }
            }
        }
        
        return -1;
    }
};