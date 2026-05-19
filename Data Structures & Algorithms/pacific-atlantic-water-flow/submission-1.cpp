class Solution {
public:
    int n1;
    int n2;
    int directions[4][2] = {{1, 0}, {-1, 0},{0, 1}, {0, -1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n1 = heights.size();
        n2 = heights[0].size();
        vector<vector<bool>> pacific(n1,vector<bool>(n2,false));
        vector<vector<bool>> atlantic(n1,vector<bool>(n2,false));
        vector<vector<int>> res;
        for(int j = 0; j < n2; j++){
           dfs(0,j,pacific,heights);
           dfs(n1-1,j,atlantic,heights);
        }
        for(int i = 0; i < n1; i++){
           dfs(i,0,pacific,heights);
           dfs(i,n2-1,atlantic,heights);
        }
        for(int r = 0; r < n1; r++){
            for(int c= 0; c < n2; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
    void dfs(int r, int c, vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[r][c] = true;
        for(int i = 0; i < 4; i++){
            int nr = r+directions[i][0];
            int nc = c+directions[i][1];
            if(nr>= 0 && nr < n1 && nc >= 0 && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                dfs(nr,nc,ocean,heights);
            }
        }
    }
};
