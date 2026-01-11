class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }

        int m = matrix.length;
        int n = matrix[0].length;

        int[] heights = new int[n];
        int[] leftBoundaries = new int[n];
        int[] rightBoundaries = new int[n];
        Arrays.fill(rightBoundaries, n);

        int maxRectangle = 0;

        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = n;

            updateHeightsAndLeftBoundaries(matrix[i], heights, leftBoundaries, left);

            updateRightBoundaries(matrix[i], rightBoundaries, right);

            maxRectangle = calculateMaxRectangle(heights, leftBoundaries, rightBoundaries, maxRectangle);
        }

        return maxRectangle;
    }

    private void updateHeightsAndLeftBoundaries(char[] row, int[] heights, int[] leftBoundaries, int left) {
        for (int j = 0; j < heights.length; j++) {
            if (row[j] == '1') {
                heights[j]++;
                leftBoundaries[j] = Math.max(leftBoundaries[j], left);
            } else {
                heights[j] = 0;
                leftBoundaries[j] = 0;
                left = j + 1;
            }
        }
    }

    private void updateRightBoundaries(char[] row, int[] rightBoundaries, int right) {
        for (int j = rightBoundaries.length - 1; j >= 0; j--) {
            if (row[j] == '1') {
                rightBoundaries[j] = Math.min(rightBoundaries[j], right);
            } else {
                rightBoundaries[j] = right;
                right = j;
            }
        }
    }

    private int calculateMaxRectangle(int[] heights, int[] leftBoundaries, int[] rightBoundaries, int maxRectangle) {
        for (int j = 0; j < heights.length; j++) {
            int width = rightBoundaries[j] - leftBoundaries[j];
            int area = heights[j] * width;
            maxRectangle = Math.max(maxRectangle, area);
        }
        return maxRectangle;
    }
}