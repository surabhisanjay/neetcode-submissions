class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        pq = []
        graph = defaultdict(list)
        dests = set()
        allvert = set()
        for src,dest in sorted(tickets, reverse=True):
            graph[src].append(dest)
        res = []
        stack = ["JFK"]
        while stack:
            curr = stack[-1]
            if(graph[curr]):
                stack.append(graph[curr].pop())
            else:
                res.append(stack.pop())
        
        return res [::-1]          

        
        