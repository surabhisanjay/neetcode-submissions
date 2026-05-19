class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        no_ways = 0
        n = len(nums)
        dp = {}
        def backTrack(i,total):
            if(i==n):
                if(total == target):
                    return 1
                else:
                    return 0
            if((i,total) in dp):
                return dp[(i,total)]
            dp[(i,total)]= backTrack(i+1,total+nums[i])+backTrack(i+1,total-nums[i])
            return dp[(i,total)]
        return backTrack(0,0)
        
    
            
