
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        vector<int> rowCount(numRows), colCount(numCols);
        unordered_map<int, pair<int, int>> numToPos;

        // Create a map to store the position of each number in the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = numToPos[num];

            // Increment the count for the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            // Check if the row or column is completely painted
            if (rowCount[row] == numCols || colCount[col] == numRows) {
                return i;
            }
        }

        return -1;  // This line will never be reached as per the problem
                    // statement
    }
};