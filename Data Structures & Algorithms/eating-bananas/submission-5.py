class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        n = len(piles)
        memo = {}
        import math
        
            
        low = 1
        high = max(piles)
        
        ans = float('inf')
        mintime = float('inf')
        while(low <= high ):
            mid = (low+high)//2
            
            time = 0
            for i in range(n):
                time += math.ceil(piles[i]/mid)
            if time <= h:
                ans = mid
                high = mid-1
            if time>h:
                low = mid +1
        return ans



            

        
