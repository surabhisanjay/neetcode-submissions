class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        res = []
        subset = []
        def dfs(i):
            if i >= n:
                if sum(subset) == target:
                    if sorted(subset.copy()) not in res:
                        res.append(sorted(subset.copy()))
            
                return
            subset.append(candidates[i])
            dfs(i+1)
            subset.pop()
            dfs(i+1)
        dfs(0)
        return res
