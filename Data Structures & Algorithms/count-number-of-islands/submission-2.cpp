class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                     islands++;
                }
            }
        }
        return islands;
    }
    bool dfs(vector<vector<char>>& grid,int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0'){
            return false;
        }
        grid[i][j] = '0';
        
        
        return 
           dfs(grid,i+1,j) ||
           dfs(grid,i-1,j) ||
           dfs(grid,i,j+1) ||
           dfs(grid,i,j-1);
    }
};
