class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        n = len(nums)
        subsets = []
        nums.sort()
        def backTrack(i,subset):
            if i==n:
                subsets.append(subset.copy())
                return

            subset.append(nums[i])
            backTrack(i+1,subset)
            subset.pop()
            #skipping all the duplicates: 
            while((i+1)<n and nums[i]==nums[i+1]):
                i+=1 
            backTrack(i+1,subset)
        
        backTrack(0,[])
        return subsets
            