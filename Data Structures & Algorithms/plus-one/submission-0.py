import math
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        n = len(digits)

        for i in range(n-1,-1,-1):
            num += int(digits[n-1-i]*math.pow(10,i))
        num += 1
        res = []
        while(num > 0):
            rem = num % 10
            num = num//10
            res.append(rem)
        return res[::-1]