class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        subset = []
        res = []
        used = [False]*n
        def backTrack(subset):
            if len(subset) == n:
                res.append(subset[:])
                return 
            for i in range(n):
                if not used[i]:
                    used[i] = True
                    subset.append(nums[i])
                    backTrack(subset)
                    subset.pop()
                    used[i] = False
    
           
        backTrack(subset)
        return res
        
                
