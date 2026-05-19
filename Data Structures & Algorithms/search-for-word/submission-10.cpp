class Solution {
public:
    set<pair<int,int>>path;
    int ROWS;
    int COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
                
            }
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<char>>& board,string word,int w){
        if(w == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= ROWS || j >= COLS || board[i][j] != word[w] || path.count({i,j})){
            return false;
        }
        path.insert({i,j});
        bool res = dfs(i+1,j,board,word,w+1)||dfs(i,j-1,board,word,w+1)||
                    dfs(i,j+1,board,word,w+1)|| dfs(i-1,j,board,word,w+1);
        path.erase({i,j});
        
        return res;
    }
};
