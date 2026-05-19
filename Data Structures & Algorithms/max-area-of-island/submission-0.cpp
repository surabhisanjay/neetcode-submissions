class Solution {
public:
    int ROWS;
    int COLS;
        std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int maxArea = INT_MIN;
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                maxArea = max(maxArea,dfs(grid,r,c));
            }
        }

        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0){
            return 0;
        }
        grid[r][c]=0;
        int Area = 1;
        for(int i = 0; i < 4; i++){
            Area +=  dfs(grid, r+directions[i][0], c+directions[i][1]);
        }
        return Area;
    }


};
