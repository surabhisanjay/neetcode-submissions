class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        edge_dict = collections.defaultdict(list)

        for i in range(len(edges)):
            src,dst = edges[i]
            edge_dict[src].append((dst, succProb[i]))
            edge_dict[dst].append((src, succProb[i]))
        visited = set()
        minHeap = [(-1,start_node)]
        while minHeap:
            w1,n1 = heapq.heappop(minHeap)
            visited.add(n1)
            if n1 == end_node:
                return -w1
            for n2,w2 in edge_dict[n1]:
                if n2 not in visited:
                    heapq.heappush(minHeap,(w1*w2, n2))
        return 0.0