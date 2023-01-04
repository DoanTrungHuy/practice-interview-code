class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r, c = len(matrix), len(matrix[0])
        save = []
        
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    save.append((i, j))
                    
        for i, j in save:
            for x in range(r):
                matrix[x][j] = 0
            for y in range(c):
                matrix[i][y] = 0