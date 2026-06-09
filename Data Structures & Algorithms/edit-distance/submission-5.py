class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)
        dp = [[-1 for i in range(n+1)] for i in range(m+1)]
        def f(i,j):
            if (i == m):
                return n-j
            if j == n:
                return m-i
            if i<= m and j <= n and dp[i][j]!=-1:
                return dp[i][j]
            
            if word1[i] != word2[j]:
                #delete or insert
                ans = 1 + min(f(i,j+1),f(i+1,j+1),f(i+1,j))
            else:
                ans = f(i+1,j+1)
            dp[i][j] = ans
            return ans
        return f(0,0)

            