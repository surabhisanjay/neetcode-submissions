class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        directions = [[0,1],[1,0]]
        visited = set()
        res = 0
        def dfs(i,j):
            if i == m - 1 or j == n -1 :
                return 1
            if i>= m or j >= n:
                return 0
            return dfs(i,j+1) + dfs(i+1,j)

           
        return dfs(0,0)
