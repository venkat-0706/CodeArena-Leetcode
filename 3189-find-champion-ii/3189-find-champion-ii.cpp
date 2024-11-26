class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> isUndefeated(n, true);
        
        for (const auto& edge : edges) {
            int winner = edge[0];
            int loser = edge[1];
            isUndefeated[loser] = false;
        }
        
        int champion = -1;
        int championCount = 0;
        
        for (int team = 0; team < n; team++) {
            if (isUndefeated[team]) {
                champion = team;
                championCount++;
            }
        }
        
        return championCount == 1 ? champion : -1;
    }
};