class MedianFinder:

    def __init__(self):
        self.smaller = []
        self.larger = []
        

    def addNum(self, num: int) -> None:
        heapq.heappush(self.larger, -num)
        heapq.heappush(self.smaller, -heapq.heappop(self.larger))

        if len(self.smaller) > len(self.larger)+1:
            heapq.heappush(self.larger, -heapq.heappop(self.smaller))
 
    def findMedian(self) -> float:
        
        if (len(self.smaller) + len(self.larger)) % 2 == 0:
            return -(-self.smaller[0] + self.larger[0])/2
        else:
            return self.smaller[0]