class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        s = 0
        
        for i in range(n):
            for j in range(n):
                if i == j or i == n - j - 1:
                    s += mat[i][j]
        
        return s