class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int minutes= 0;
       queue<pair<int,int>> q;
       int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        } 
        
        while(fresh > 0 && !q.empty()){
            int length = q.size();
            for(int l = 0; l < length; l++){
                auto curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                for(int i = 0; i < 4; i++){
                    int r = row+directions[i][0];
                    int c = col+directions[i][1];
                    if(r >= 0 && c >= 0 && r < m  && c < n && grid[r][c] == 1){
                        grid[r][c] = 2;
                        q.push({r,c});
                        fresh--;
                    }  
                }   
            }
            minutes++;
        }
        return fresh == 0 ? minutes:-1;

    }
};
