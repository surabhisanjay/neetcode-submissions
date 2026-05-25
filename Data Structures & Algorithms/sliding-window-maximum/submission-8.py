class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        currmax = max(nums[:k])
        maxes = []
        currwin = nums[:k]
        currmax = max(nums[:k])
        maxes.append(currmax)
        for i in range(k,len(nums)):
            currwin.pop(0)
            currwin.append(nums[i])
            
            maxes.append(max(currwin))
        return maxes