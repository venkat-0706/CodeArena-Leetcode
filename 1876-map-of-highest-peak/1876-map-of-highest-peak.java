class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int[] dx = { 0, 0, 1, -1 }; 
        int[] dy = { 1, -1, 0, 0 }; 

        int rows = isWater.length;
        int columns = isWater[0].length;
        int[][] cellHeights = new int[rows][columns];
        for (int[] row : cellHeights) {
            Arrays.fill(row, -1);
        }
        Queue<int[]> cellQueue = new LinkedList<>();
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                if (isWater[x][y] == 1) {
                    cellQueue.add(new int[] { x, y });
                    cellHeights[x][y] = 0;
                }
            }
        }

        int heightOfNextLayer = 1;
        while (!cellQueue.isEmpty()) {
            int layerSize = cellQueue.size();
            for (int i = 0; i < layerSize; i++) {
                int[] currentCell = cellQueue.poll();
                for (int d = 0; d < 4; d++) {
                    int neighborX = currentCell[0] + dx[d];
                    int neighborY = currentCell[1] + dy[d];
                    if (
                        isValidCell(neighborX, neighborY, rows, columns) &&
                        cellHeights[neighborX][neighborY] == -1
                    ) {
                        cellHeights[neighborX][neighborY] = heightOfNextLayer;
                        cellQueue.add(new int[] { neighborX, neighborY });
                    }
                }
            }
            heightOfNextLayer++; 
        }

        return cellHeights;
    }
    private boolean isValidCell(int x, int y, int rows, int columns) {
        return x >= 0 && y >= 0 && x < rows && y < columns;
    }
}