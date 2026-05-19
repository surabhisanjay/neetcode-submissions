class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        matrix.reverse()
        for i in range(m):
            for j in range(i+1,m):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
        

            