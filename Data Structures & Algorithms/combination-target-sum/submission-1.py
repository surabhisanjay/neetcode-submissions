class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(i,wind,target):
            if target == 0:
                res.append(wind[:])
                return 
            if target < 0 or i >= len(nums):
                return
            #keep
            wind.append(nums[i])
            dfs(i,wind,target-nums[i])
            wind.pop()
            #next 
            dfs(i+1,wind,target)
            return
        
        dfs(0,[],target)
        return res

