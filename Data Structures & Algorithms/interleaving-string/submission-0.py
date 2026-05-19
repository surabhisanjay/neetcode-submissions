class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False

        p1 = 0
        p2 = 0
        n1 = len(s1)
        n2 = len(s2)
        dp = {}
        #p3 = p1+p2
    
        def dfs (p1,p2):
            
            if (p1+p2) == len(s3):
               return p1 == len(s1) and p2 == len(s2)
            
            if (p1,p2) in dp:
                return dp[(p1,p2)]
            
            match1 = p1 < len(s1) and s1[p1] == s3[p1+p2] and dfs(p1+1,p2) 
            match2 = p2 < len(s2) and s2[p2] == s3[p1+p2] and dfs(p1,p2+1) 
            
            dp[(p1,p2)] = match1 or match2
            
            return dp[(p1,p2)]
        return dfs(0,0)


            
            

        
