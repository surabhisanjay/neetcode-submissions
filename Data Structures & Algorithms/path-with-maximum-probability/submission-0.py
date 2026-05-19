class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        edge_dict = collections.defaultdict(list)
    
        for i in range(len(edges)):
            src,dst = edges[i]
            edge_dict[src].append((dst,succProb[i]))
            edge_dict[dst].append((src,succProb[i]))

        minHeap = [(-1,start_node)]
        visited = set()
        while minHeap:
            w1,n1= heapq.heappop(minHeap)
            visited.add(n1)
            if n1 == end_node:
                return -w1
            
            for n2,w2 in edge_dict[n1]:
                if n2 not in visited:
                    heapq.heappush(minHeap,(w1*w2, n2))

        return 0.0
# class Solution:
#     def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
#         adj = collections.defaultdict(list)
#         for i in range(len(edges)):
#             src, dst = edges[i]
#             adj[src].append((dst, succProb[i]))
#             adj[dst].append((src, succProb[i]))

#         pq = [(-1, start_node)]
#         visit = set()

#         while pq:
#             prob, cur = heapq.heappop(pq)
#             visit.add(cur)

#             if cur == end_node:
#                 return -prob

#             for nei, edgeProb in adj[cur]:
#                 if nei not in visit:
#                     heapq.heappush(pq, (prob * edgeProb, nei))

#         return 0.0
            