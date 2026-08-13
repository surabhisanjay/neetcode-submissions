class TrieNode:
    def __init__(self,value):
        self.value = value
        self.isWord = False
        self.children ={}
class WordDictionary:

    def __init__(self):
        self.root = TrieNode("")

    def addWord(self, word: str) -> None:
        curr = self.root

        for ch in word:
            if ch not in curr.children:
                curr.children[ch] = TrieNode(ch)
            curr = curr.children[ch]
        curr.isWord = True
    

    def search(self, word: str) -> bool:
        curr = self.root
        def dfs(node, index):
            if index == len(word):
                return node.isWord

            ch = word[index]

            if ch != ".":
                if ch not in node.children:
                    return False

                return dfs(node.children[ch], index + 1)

            # ch == "."
            for child in node.children.values():
                if dfs(child, index + 1):
                    return True
            return False
        return dfs(self.root,0)
