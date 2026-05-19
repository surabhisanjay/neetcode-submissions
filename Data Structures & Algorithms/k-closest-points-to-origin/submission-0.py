class Solution:
    def euclid(self,p1,p2):
        x1 = p1[0]
        x2 = p2[0]
        y1 = p1[1]
        y2 = p2[1]
        return (x1-x2)**2+(y1-y2)**2
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        min_heap = []
        for point in points:
            dist= self.euclid(point,(0,0))
            heapq.heappush(min_heap, (dist,point))
        res= []
        for _ in range(k):
            point = heapq.heappop(min_heap)[1]
            res.append(point)

        return res


