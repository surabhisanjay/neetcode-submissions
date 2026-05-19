class Solution {
public:
    int uniquePaths(int m, int n) {
        int M = m;
        int N = n;
        vector<vector<int>> dp(M+1,vector<int> (N+1,0));
        dp[M-1][N-1] = 1;
        for(int i = M-1; i>= 0; i--){
            for(int j = N-1; j>= 0; j--){
                dp[i][j]+= dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
