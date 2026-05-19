class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        node = self.root
        for ch in word: 
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.isWord = True

class Solution:

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m = len(board)
        n = len(board[0])
        path = ""
        result = set()
        trie = Trie()
        for word in words: 
            trie.insert(word)
        def dfs(i,j,node, path):
            if node.isWord: 
                result.add(path)
            if i >= m or j >= n or i < 0 or j < 0:
                return
            temp = board[i][j] 
            
            if temp not in node.children: 
                return 
            board[i][j] = "#"
            dfs(i+1,j, node.children[temp], path+temp)
            dfs(i-1,j, node.children[temp], path+temp)
            dfs(i,j+1, node.children[temp], path+temp)
            dfs(i,j-1, node.children[temp], path+temp)
            board[i][j] =  temp
        
        for i in range(m):
            for j in range(n):
                dfs(i,j,trie.root,"")
        return list(result)


