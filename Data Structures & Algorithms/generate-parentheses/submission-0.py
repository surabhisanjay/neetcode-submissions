class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        paths = []
        dp = [[-1]*n for i in range(n)]

        def backtrack(o,c,path):
            if len(path) == 2*n and o == c:
                nonlocal paths
                paths.append("".join(path))
                return 
            
            if o < n:
                path.append("(")
                backtrack(o+1,c,path)
                path.pop()
            if c < o:
                path.append(")")
                backtrack(o,c+1,path)
                path.pop()
        
        backtrack(0,0,[])
        return paths
