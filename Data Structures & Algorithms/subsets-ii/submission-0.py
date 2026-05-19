class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        subsets = set()
        def backTrack(i,subset):
            if i==n:
                subsets.add(tuple(subset))
                return

            subset.append(nums[i])
            backTrack(i+1,subset)
            subset.pop()
            backTrack(i+1,subset)
        backTrack(0,[])
        return [list(s) for s in subsets]
            