class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        edges = collections.defaultdict(list)
        n1 = len(grid)
        n2 = len(grid[0])
        minHeap = [(grid[0][0],(0,0))]
        res = 0
        directions = [(-1,0),(0,-1),(0,1),(1,0)]
        visited = set()
        while minHeap:
            height, (i, j) = heapq.heappop(minHeap)
            visited.add((i,j))

            if (i,j) == (n1-1, n2-1):
                return height

            for dr, dc in directions:
                dy = dr + i 
                dx = dc + j
                if 0 <= dy < n1 and 0 <= dx < n2 and (dy, dx) not in visited:
                    heapq.heappush(minHeap, (max(height, grid[dy][dx]), (dy, dx)))
        return 0


