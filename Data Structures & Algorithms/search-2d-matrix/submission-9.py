class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        ans = ()
        rmid = 0
        rlow = 0
        r = 0
        rhigh = m-1
        while(rlow <= rhigh):
            rmid = (rlow+rhigh)//2
            if target > matrix[rmid][n-1]:
                rlow = rmid+1
            elif target < matrix[rmid][0]:
                rhigh = rmid-1
            else:
                r = rmid
                break


        
        low = 0
        high = n-1
        while(low <= high):
            mid= (low+high)//2
            if target > matrix[r][mid]:
                low = mid+1
            elif target < matrix[r][mid]:
                high= mid-1
            else:
                return True
        return False