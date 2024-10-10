class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int row = 0; row < n / 2; row++) {
            for (int col = row; col < n - row - 1; col++) {
                // Swap the top-left and top-right cells in the current group
                swap(matrix[row][col], matrix[col][n - 1 - row]);
                // Swap the top-left and bottom-right cells in the current group
                swap(matrix[row][col], matrix[n - 1 - row][n - 1 - col]);
                // Swap the top-left and bottom-left cells in the current group
                swap(matrix[row][col], matrix[n - 1 - col][row]);
            }
        }
    }
};