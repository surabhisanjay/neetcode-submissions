class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    
        res = []
        
        
        #merge overlapping intervals
        intervals.sort(key = lambda x: x[0])
        prevEnd = -1
        res = [intervals[0]]
        for i in range(1,len(intervals)):
            if intervals[i][0] <= res[-1][1]:
                res[-1][1] = max(intervals[i][1],res[-1][1])
            else:
                res.append(intervals[i])
        return res