class Solution {
    public int max;
    public int findMaxFish(int[][] grid) {
        int rlen = grid.length;
        int clen = grid[0].length;
        int answer = 0;
        boolean visited[][] = new boolean[rlen][clen];
        for(int i=0;i<rlen;i++){
            for(int j=0;j<clen;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    max = 0;
                    dfs(grid, rlen, clen, visited, i, j);
                    answer = Math.max(max, answer );
                }
            }
        }
        return answer;
    }
    
    public void dfs(int[][] grid, int rlen, int clen, boolean[][] visited, int i, int j){
        if(i<0 || i>=rlen || j<0 || j>=clen || visited[i][j] || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        max += grid[i][j];
        dfs(grid, rlen, clen, visited, i+1, j);
        dfs(grid, rlen, clen, visited, i-1, j);
        dfs(grid, rlen, clen, visited, i, j+1);
        dfs(grid, rlen, clen, visited, i, j-1);
    }
}