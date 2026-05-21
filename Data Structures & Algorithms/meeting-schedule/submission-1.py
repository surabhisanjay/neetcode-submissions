"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        prevend = 0
        intervals.sort(key = lambda x: x.start)
        for i in range(len(intervals)):
            start = intervals[i].start
            end = intervals[i].end
            if start < prevend:
                return False
            prevend = end
        return True