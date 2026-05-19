class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l = 0
        r = 0
        n = len(nums)
        maxsum = nums[0]
        currsum = 0
        while(r < n):
            if currsum<0:
                currsum = 0

            currsum += nums[r]
            maxsum = max(maxsum,currsum)
    
            r+=1
        return maxsum 