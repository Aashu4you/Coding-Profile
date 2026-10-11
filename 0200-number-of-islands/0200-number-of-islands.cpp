class Solution {
public:
    void dfs(vector<vector<char>>&grid,int row, int col){
        int rows = grid.size() , cols = grid[0].size();
        if(row<0 || row>=rows || col<0 || col>=cols || grid[row][col]=='0'){
            return;
        }
        grid[row][col]='0';
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int row = 0 ; row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]=='1'){
                    islands++;
                    dfs(grid,row,col);
                }
            }
            
        }
        return islands;
    }
};