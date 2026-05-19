class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        
        
        i = 0
        n = len(nums)
        subsum= 0
    
        rem_indices = {0:-1}
        prefix = 0
        while( i < n):
            prefix+= nums[i]
            r = prefix%k
            if r in rem_indices:
                if i - rem_indices[r] >= 2:
                    return True
                
            else:
                rem_indices[r] = i
            i+=1

        return False 