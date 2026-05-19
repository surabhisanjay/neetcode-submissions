class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);

        int n = cost.size();
        int i = 2;
        while(i <= n){
            dp[i] = min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
            i++;
        }
        return dp[n];
    }
};
