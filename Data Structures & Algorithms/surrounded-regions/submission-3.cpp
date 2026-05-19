class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> q;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                bfs_search(i,0,board);
            }
            if(board[i][n-1]=='O'){
                bfs_search(i,n-1,board);
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                bfs_search(0,j,board);
            }
            if(board[m-1][j]=='O'){
                bfs_search(m-1,j,board);
            }
        }
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c]=='O'){
                    board[r][c] = 'X';
                }
                else if(board[r][c]=='B'){
                    board[r][c]= 'O';
                }
            }
        }
    }
    
    void bfs_search(int i, int j,vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size()|| j>=board[0].size() || board[i][j]!='O'){
            return;
        }
        board[i][j] = 'B';
        bfs_search(i,j+1,board);
        bfs_search(i,j-1,board);
        bfs_search(i+1,j,board);
        bfs_search(i-1,j,board);
        
    }
};
