class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = defaultdict(list)
        letters = set()
        
        for w in words:
            for l in w:
                letters.add(l)
                adj[l] = []
        n = len(words)
        indegree = {l : 0 for l in letters}
        for i in range(1, len(words)):
            w1, w2 = words[i - 1], words[i]
            
            # Check for invalid prefix rule (e.g., ["abc", "ab"])
            if len(w1) > len(w2) and w1.startswith(w2):
                return ""
            
            # Find first differing character
            for j in range(min(len(w1), len(w2))):
                if w1[j] != w2[j]:
                    # w1[j] comes BEFORE w2[j] in alien alphabet
                    if w2[j] not in adj[w1[j]]:
                        adj[w1[j]].append(w2[j])
                        indegree[w2[j]] += 1
                    break  #
            
        q = deque([l for l in indegree if indegree[l] == 0])
        res = []
        visited = set()
        while q:
            
            curr = q.popleft()
            res.append(curr)
            if curr in visited:
                continue
            
            visited.add(curr)

            for nei in adj[curr]:
                indegree[nei] -= 1
                if indegree[nei] == 0 and nei not in visited:
                    q.appendleft(nei)
        
        return "".join(res) if len(res) == len(letters) else ""
            
                

                    


                

