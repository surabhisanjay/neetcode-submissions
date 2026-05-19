class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n= len(s)
        dp = [False]*(n+1)
        dp[0] = True
        l = 0
        r = 1
        for r in range(1,n+1):
            for l in range(r):
                if(dp[l] and s[l:r] in wordDict):
                    dp[r] = True
            
        return dp[n]