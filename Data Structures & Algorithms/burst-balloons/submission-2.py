class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        # Extend the list 'a' with 1s at both ends
        nums.insert(0, 1)
        nums.append(1)

        # Create a 2D DP table initialized with -1s
        dp = [[-1] * (n + 2) for _ in range(n + 2)]

        def f(i, j):
            if i > j:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            maxi = float('-inf')
            for ind in range(i, j + 1):
                cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1) + f(ind + 1, j)
                maxi = max(maxi, cost)
            dp[i][j] = maxi
            return maxi

        return f(1, n)