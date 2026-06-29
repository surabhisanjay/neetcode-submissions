class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        curr = Counter()
        lastapp = {}
        firstapp = {}  # FIXED: Use a regular dict instead of Counter
        n = len(s)

        for i in range(n):
            lastapp[s[i]] = i
            # FIXED: Only set the first appearance if we haven't seen it yet
            if s[i] not in firstapp:
                firstapp[s[i]] = i
        intervals = []
        res = []
        sset = set(s)
        for i in s:
            intervals.append([firstapp[i],lastapp[i]])
        #merge overlapping intervals
        intervals.sort(key = lambda x: x[0])
        prevEnd = -1
        res = [intervals[0]]
        for i in range(1,len(intervals)):
            if intervals[i][0] <= res[-1][1]:
                res[-1][1] = max(intervals[i][1],res[-1][1])
            else:
                res.append(intervals[i])
        final =[]
        for l,r in res:
            final.append(r-l+1)
        return final

        
