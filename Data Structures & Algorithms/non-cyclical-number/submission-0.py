class Solution:
    def isHappy(self, n: int) -> bool:
        def digsum(n):
            totsum = 0
            while(n > 0):
                rem = n % 10 
                n = n // 10
                totsum += rem**2
            return totsum
        initsum = digsum(n)
        currsum = digsum(initsum)
        maxsum = 0
        seenset = set()
        while(currsum > 0):
            currsum = digsum(currsum)
            if currsum not in seenset:
                seenset.add(currsum)
            else:
                return False

            if currsum == 1:
                return True

        return False
            


