class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        path = set()
        m = len(board)
        n = len(board[0])
        
        def dfs(i,j,k):
            if k == len(word):
                return True
            if i >= m or i < 0 or j >= n or j < 0 or (i,j) in path or board[i][j] != word[k]:
                return False
            
            path.add((i,j))
            res = dfs(i+1,j,k+1) or dfs(i,j+1,k+1) or dfs(i-1,j,k+1) or dfs(i,j-1,k+1)
            path.remove((i,j))

            return res

        for i in range(m):
            for j in range(n):
                if(dfs(i,j,0)):
                    return True
        return False


