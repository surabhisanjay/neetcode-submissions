class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalin(word):
            if(word == word[::-1]):
                return True
        n = len(s)
        res =[]
        currPart = []
        def dfs(i,j):
            if(j>=len(s)):
                if(i == j):
                    res.append(currPart.copy())
                return
            if(isPalin(s[i:j+1])):
                currPart.append(s[i:j+1])
                dfs(j+1,j+1)
                currPart.pop()
            dfs(i,j+1)
            
            
        dfs(0,0)
        return res

            
