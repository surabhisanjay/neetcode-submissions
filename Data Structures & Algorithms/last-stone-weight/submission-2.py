class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = []
        for stone in stones:
            heapq.heappush(max_heap, -1*stone)
        
        while(len(max_heap))>1:
            stone1 = heapq.heappop(max_heap)
            stone2 = heapq.heappop(max_heap)
            new_stone= abs(stone1-stone2)
            heapq.heappush(max_heap,-1*new_stone)

        return -1*max_heap[-1] if len(max_heap) == 1 else 0
