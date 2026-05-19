from collections import deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        n = len(beginWord)
        memo = {}
        queue = deque([(beginWord,1)])
        ops = 0
        wordlen = len(beginWord)
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0
        while queue:
            currword,steps = queue.popleft()
            if currword == endWord:
                return steps

            for i in range(wordlen):
                
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    newword = currword[:i]+ch+currword[i+1:]
                    if newword in wordSet:
                        queue.append((newword,steps+1))
                        wordSet.remove(newword)
                    
        return 0