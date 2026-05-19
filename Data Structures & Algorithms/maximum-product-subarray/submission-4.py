class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curmin = 1
        curmax = 1
        tmp = 1
        res = nums[0]
        for num in nums: 
            tmp = curmax*num
            curmax = max(curmax*num,num*curmin,num)
            curmin = min(tmp,num*curmin,num)
            res = max(res,curmax)

        return res