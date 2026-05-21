class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        pq=[(src,0)]
        adj = defaultdict(list)
        
        for f in flights:
            adj[f[0]].append((f[1],f[2]))
        res = 0
        queue = [(0,(src,0))]
        dist = [float('inf') for i in range(n)]

        while(queue):
            stops,pair = queue.pop(0)
            curr, cost = pair

            if stops> k:
                continue
            for node in adj[curr]:
                neicost = node[1]
                nei = node[0]
                if cost+ neicost < dist[nei] and stops <= k:
                    dist[nei] = cost+neicost
                    queue.append((stops+1,(nei,cost+neicost)))
        return dist[dst] if dist[dst] != float('inf') else -1
