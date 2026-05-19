class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n= len(grid[0])
        directions= [(0,1),(1,0),(0,-1),(-1,0)]
        ones= []
        count = 0
        def dfs(i,j):
            if not ((0 <= i < m) and (0 <= j < n)) or grid[i][j] == "0":
                return;
            
            grid[i][j] = "0"
            for d in directions:
                dr = d[0] + i
                dc = d[1] + j
                dfs(dr,dc)
            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    dfs(i,j)
                    count+=1
        
        return count
    
    
        
        