class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        dp = [[-1] * n for _ in range(n)]

        def f(i, j):
            if i + 1 == j:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            ans = 0

            for ind in range(i + 1, j):
                cost = (
                    nums[i] * nums[ind] * nums[j]
                    + f(i, ind)
                    + f(ind, j)
                )

                ans = max(ans, cost)

            dp[i][j] = ans
            return ans

        return f(0, n - 1)