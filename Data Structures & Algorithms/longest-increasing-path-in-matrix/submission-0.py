class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        directions= [(0,1),(1,0),(-1,0),(0,-1)]
        dp = [[-1 for i in range(n)] for i in range(m)]

        def dfs(i,j,prev):
            if i >= m or j >= n or i < 0 or j < 0:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            prev = matrix[i][j]
            maxlength = 0
            for d in directions:
                ni = d[0]+i
                nj = d[1]+j
                if 0 <= ni  < m and 0 <= nj < n and matrix[ni][nj] > matrix[i][j]:
                    maxlength = max(dfs(ni,nj,prev),maxlength)
            dp[i][j] = 1+maxlength
            return dp[i][j]
        res = 0
        for i in range(m):
            for j in range(n):
                res = max(res, dfs(i,j,-1))
        
        return res

        