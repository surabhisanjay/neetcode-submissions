class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        
        def isSubstring(i,j):
            palin_count=0
            while( i >=0 and j<n and s[i] == s[j]): 
                palin_count +=1
                i-=1
                j+=1
            return palin_count
        palin_count = 0
        for i in range(n):
            palin_count +=isSubstring(i,i)+isSubstring(i,i+1)
            
        return palin_count
