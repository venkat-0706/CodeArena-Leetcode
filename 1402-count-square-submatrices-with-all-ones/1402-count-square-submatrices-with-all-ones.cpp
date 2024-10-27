class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Get dimensions of the matrix
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns
        
        // Create a DP table with same dimensions as matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Variable to store total count of squares
        int ans = 0;
        
        // Initialize first column of DP table
        // Each cell in first column can only form a 1x1 square if matrix[i][0] = 1
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];  // Add the count of squares from the first column
        }
        
        // Initialize first row of DP table
        // Each cell in first row can only form a 1x1 square if matrix[0][j] = 1
        for (int j = 1; j < m; j++) {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];  // Add the count of squares from the first row
        }
        
        // Fill the DP table for remaining cells
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                // Only process if current cell in matrix is 1
                if(matrix[i][j] == 1) {
                    // For each cell, check the minimum value among:
                    // 1. Left cell (dp[i][j-1])
                    // 2. Top cell (dp[i-1][j])
                    // 3. Top-left diagonal cell (dp[i-1][j-1])
                    // Add 1 to this minimum value
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                // Add current cell's value to total count
                ans += dp[i][j];
            }
        }
        
        // Return total count of squares
        return ans;
    }
};