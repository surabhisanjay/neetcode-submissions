class TrieNode:
    def __init__(self):
        self.children = [None]*26
        self.endOfWord = False
class PrefixTree:

    def __init__(self):
        self.root = TrieNode()


    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if curr.children[ord(c) -ord('a')] == None:
                curr.children[ord(c) -ord('a')] = TrieNode()
            curr = curr.children[ord(c) -ord('a')]
        curr.endOfWord = True
            

    def search(self, word: str) -> bool:
        curr = self.root
        i = 0
        found = True
        for c in word:
            if curr.children[ord(c) -ord('a')] == None:
                return False
            curr = curr.children[ord(c) -ord('a')]
        return curr.endOfWord



    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        i = 0
        found = True
        for c in prefix:
            if curr.children[ord(c) -ord('a')] == None:
                return False
            curr = curr.children[ord(c) -ord('a')]
        return True
        