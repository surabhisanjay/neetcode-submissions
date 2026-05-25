class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        n = len(matrix[0])
        ans = ()
        for r in range(m):
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