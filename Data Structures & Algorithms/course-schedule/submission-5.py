class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = {i :[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            adj[crs].append(pre)

        visiting = set()
        def dfs(crs):
            if crs in visiting:
                return False
            if len(adj[crs]) == 0:
                return True
            visiting.add(crs)
            for nei in adj[crs]:
                if not dfs(nei):
                    return False
            visiting.remove(crs)
            adj[crs] = []
            return True
        
        for c in range(numCourses):
            if not dfs(c):
                return False
        return True
