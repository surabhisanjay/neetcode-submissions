class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        vector<vector<int>> dp(M+1,vector<int>(N+1,0));
        dp[M-1][N-1]=1;
        for(int i = M-1; i >= 0; i--){
            for(int j = N-1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] += dp[i+1][j]+dp[i][j+1];
                }
    
            }
        }
        return dp[0][0];
    }
};