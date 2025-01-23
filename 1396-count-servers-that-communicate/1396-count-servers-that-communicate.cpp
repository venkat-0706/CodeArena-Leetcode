class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();
        int communicableServersCount = 0;
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;
                    for (int otherCol = 0; otherCol < numCols; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }
                    if (canCommunicate) {
                        communicableServersCount++;
                    } else {
                        for (int otherRow = 0; otherRow < numRows; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }
                        if (canCommunicate) {
                            communicableServersCount++;
                        }
                    }
                }
            }
        }

        return communicableServersCount;
    }
};