class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        # dp = [1]*(n)
        
        # for r in range(1,n):
        #     for l in range(r):
        #         if (nums[r] > nums[l]):
        #             dp[r] = max(dp[r], dp[l] + 1)
                
            
        # return max(dp)
        memo = [-1]*n
        def dfs(i):
            
            if memo[i] != -1:
                return memo[i]
            LIS = 1
            for j in range(i+1):
                if(nums[j]<nums[i]):
                    LIS = max(LIS,1+dfs(j))
            
            memo[i] = LIS
            return LIS
        return max(dfs(i) for i in range(n))
    