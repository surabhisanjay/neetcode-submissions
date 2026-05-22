class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        slen = len(s)
        tlen = len(t)
        dp = [[-1 for i in range(tlen)] for j in range(slen)]
        def helper(i,j):
            if j < 0:
                return 1
            if i < 0:
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]
            if (s[i] == t[j]):
                dp[i][j] = helper(i-1,j-1) + helper(i-1,j)
            else:
                dp[i][j] = helper(i-1,j)
            return dp[i][j]
        
        
        return helper(slen-1,tlen-1)