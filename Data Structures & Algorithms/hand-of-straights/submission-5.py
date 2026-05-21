class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        nums = {}
        curmin = float('inf')
        curmax = 0
    
        for i in hand:
            if i in nums:
                nums[i] += 1
            else:
                nums[i] = 1
            curmin = min(curmin,nums[i])
            curmax = max(curmax,nums[i])
        avail = set(nums.keys())
        
        while(avail):
            currmin = min(avail)
            i = 0
            while(i < groupSize and currmin+i in avail):
                nums[currmin+i] -= 1
                if nums[currmin+i] == 0:
                    avail.remove(currmin+i)
                i += 1
            if i <= groupSize -1:
                return False
        return True
                