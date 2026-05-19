class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j]== 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int r = row+directions[i][0];
                int c = col + directions[i][1];
                if(r<0 || c < 0 || r >= m || c >= n || grid[r][c] != INT_MAX){
                    continue;
                }
                grid[r][c] = grid[row][col]+1;
                q.push({r,c});
            }
            
        }
    }

};
