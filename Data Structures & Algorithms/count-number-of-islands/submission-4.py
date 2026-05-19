class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [(0,1),(0,-1),(1,0),(-1,0)]
        m = len(grid)
        n = len(grid[0])
        def dfs(i,j):
            if i>= m or j >= n or i<0 or j<0 or grid[i][j] =="0":
                return 
            grid[i][j] = "0"
            for d in directions:
                dfs(i+d[0],j+d[1])

        count = 0
        for i in range(0,m):
            for j in range(0,n):
                if(grid[i][j]=="1"):
                    dfs(i,j)
                    count += 1
        return count
        