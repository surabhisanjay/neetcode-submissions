class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        
        dp = [-1]*(n+1)

        # for i in range(2,n+1):
        #     dp[i] = min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2])
        # return dp[n]
        
        def dfs(i):
            if i >= n:
                return 0
            if dp[i]!=-1:
                return dp[i]
            dp[i] = cost[i] + min(dfs(i+1), dfs(i+2))
            return dp[i]
        
        return min(dfs(0),dfs(1))