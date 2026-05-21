class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        def mypow(x,i):
            if i == 0:
                return 1
            
            half = mypow(x, int(i / 2))
            if i % 2 == 0:
                return half * half
            else:
                return half * half * (x if i > 0 else 1/x)
        return mypow(x,n)