class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for (int row = 0; row < n / 2; row++) {
            for (int col = row; col < n - row - 1; col++) {
                // Swap the top-left and top-right cells in the current group
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][n - 1 - row];
                matrix[col][n - 1 - row] = temp;

                // Swap the top-left and bottom-right cells in the current group
                temp = matrix[row][col];
                matrix[row][col] = matrix[n - 1 - row][n - 1 - col];
                matrix[n - 1 - row][n - 1 - col] = temp;

                // Swap the top-left and bottom-left cells in the current group
                temp = matrix[row][col];
                matrix[row][col] = matrix[n - 1 - col][row];
                matrix[n - 1 - col][row] = temp;
            }
        }
    }
}