class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int row = r+directions[i][0];
                int col = c+directions[i][1];
                if(row >= 0 && col >= 0 && row<grid.size() && col <= grid[0].size() && grid[row][col]==INF){
                    grid[row][col] = 1+grid[r][c];
                    q.push({row,col});
                }
            }
        }
        
    }

};
