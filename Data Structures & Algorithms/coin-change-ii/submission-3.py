class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount + 1)] for _ in range(n)]
        
        def f(i, rem):
            # Base Case 1: Successfully formed the target amount
            if rem == 0:
                return 1
            # Base Case 2: Out of bounds or went over budget
            if rem < 0 or i >= n:
                return 0
                
            # If we've already calculated this state, return it
            if dp[i][rem] != -1:
                return dp[i][rem]
            
            # Choice 1: Skip this coin type entirely, move to the next index
            skip_coin = f(i + 1, rem)
            
            # Choice 2: Use this coin once, stay at the same index 'i' to allow re-use
            take_coin = f(i, rem - coins[i])
            
            # Save the result to our manual table and return
            dp[i][rem] = skip_coin + take_coin
            return dp[i][rem]
            
        return f(0, amount)