class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
        while(fresh>0 && !q.empty()){
            int length = q.size();
            for(int l = 0; l < length; l++){
                int r = q.front().first;
            int c = q.front().second;
            q.pop();
           
            for(int i = 0; i < 4; i++){
                int row = r+directions[i][0];
                int col = c+directions[i][1];
                if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col]==1){
                    grid[row][col] = 2;
                    fresh--;
                    q.push({row,col});
                }
            }
            
            }
            minutes++;
        }
        return fresh == 0? minutes: -1;

    }
};
