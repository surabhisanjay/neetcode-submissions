class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        pq = []
        graph = defaultdict(list)
        dests = set()
        allvert = set()
        for src,dest in sorted(tickets, reverse=True):
            graph[src].append(dest)
        res = []
        
        def dfs(curr):
            
            while(graph[curr]):
                nxt = graph[curr].pop()
                dfs(nxt)

            res.append(curr)
        dfs("JFK")
        return res [::-1]          

        
        