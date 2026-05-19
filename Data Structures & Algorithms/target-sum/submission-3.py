class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = {}
        n = len(nums)
        def dfs(i, currsum):
            if(i >= n):
                if(currsum == target):
                    return 1
                else:
                    return 0
            if (i,currsum) in dp:
                return dp[(i,currsum)]
            
            dp[(i,currsum)]= dfs(i+1, currsum+nums[i])+dfs(i+1,currsum-nums[i])
            return dp[(i,currsum)]
        return dfs(0,0)
        