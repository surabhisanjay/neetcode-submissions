class Solution {
public:
   vector<vector<int>> directions = {{1,0},{0,1},{0,-1},{-1,0}};
   bool pacific,atlantic;
   int ROWS;
   int COLS;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> coord(heights.size(),vector<bool> (heights[0].size(),false));
        for(int i = 0; i< heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                pacific = false;
                atlantic = false;
                dfs(heights,i,j,INT_MAX);
                if(pacific && atlantic){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& heights, int i, int j,int prevVal){
        if(i < 0 || j < 0 ){
            pacific = true;
            return;

        }
        if(i >= ROWS ||j >= COLS){
            atlantic = true;
            return;
        }
        if(heights[i][j] > prevVal){
            return;
        }
        int tmp = heights[i][j];
        heights[i][j] = INT_MAX;
        for(auto& dir: directions){
            dfs(heights,i+dir[0],j+dir[1],tmp);
            if(pacific && atlantic){
                break;
            }
        }
        heights[i][j] = tmp;
    }
};
