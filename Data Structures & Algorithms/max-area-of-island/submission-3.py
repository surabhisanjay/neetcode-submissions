class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        m = len(grid)
        directions = [(0,1),(1,0),(0,-1),(-1,0)]
        
        visited = []
        def dfs(i,j):
            if i >= m or j >= n or i < 0 or j < 0 or (i,j) in visited or grid[i][j] == 0:
                return 0
            visited.append((i,j))
            return 1+dfs(i-1,j)+dfs(i,j-1)+dfs(i+1,j)+dfs(i,j+1)
        maxcount = 0

        for i in range(m):
            for j in range(n):
                maxcount = max(dfs(i,j),maxcount)
        return maxcount

