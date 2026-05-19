class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = {i:[] for i in range(numCourses)}

        for crs,pre in prerequisites:
            adj[crs].append(pre)
        
        visit = set()
        cycle = set()
        result = []

        def dfs(crs):
            if crs in visit:
                return True
            if crs in cycle:
                return False
            
            cycle.add(crs)
            for n in adj[crs]:
                if not dfs(n):
                    return False
            cycle.remove(crs)
            visit.add(crs)
            result.append(crs)
            return True
        for c in range(numCourses):
            if not dfs(c):
                return []
        return result


