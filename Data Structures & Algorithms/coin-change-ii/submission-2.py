class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        n = len(coins)
        dp={}
        
        no_ways = 0
        def dfs(i,target):
            if(i>= n or target < 0):
                return 0
            if(target == 0):
                return 1
            if (i,target) in dp:
                return dp[(i,target)]
            dp[(i,target)] = dfs(i,target-coins[i])+dfs(i+1,target)
            return dp[(i,target)]
            
        return dfs(0,amount)


