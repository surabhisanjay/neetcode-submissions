class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[-1]*n for i in range(n)]
        maxi = 0
        maxj = 0
 
        def dfs(i,j):
            while(i>=0 and  j < n and s[i]==s[j]):
                i-=1
                j+=1
            return i+1,j-1
        maxlen = 0
        for i in range(n): 
            ni,nj = dfs(i,i) 
            nlen = nj-ni+1
            if nlen > maxlen:
                maxi = ni
                maxj = nj
                maxlen = nlen

            di,dj = dfs(i,i+1)
            dlen = dj-di+1
            if dlen>maxlen:
                maxi = di
                maxj = dj
                maxlen = dlen


        return s[maxi:maxj+1]

