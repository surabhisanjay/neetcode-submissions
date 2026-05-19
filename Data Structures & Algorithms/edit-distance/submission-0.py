class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1 = len(word1)
        n2 = len(word2)

        dp = {}

        def dfs(i,j):
            if(i,j) in dp:
                return dp[(i,j)]
            if i == n1:
                return n2 - j
          
            if j == n2:
                return n1 - i
            if word1[i] == word2[j]:
                dp[(i,j)] = dfs(i+1,j+1)
            else:
                insert = 1+dfs(i,j+1)
                delete = 1+dfs(i+1,j)
                replace = 1+dfs(i+1,j+1)
                ops = min(insert,delete,replace)
                dp[(i,j)] = ops
            return dp[(i,j)]
        return dfs(0,0)
            
            