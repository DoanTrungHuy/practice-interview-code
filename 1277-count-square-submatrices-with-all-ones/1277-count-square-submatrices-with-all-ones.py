class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        # 0 1 1 1
        # 1 1 2 2
        # 1 1 2 3
        
        n, m = len(matrix), len(matrix[0])
        
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] > 0:
                    matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1
                
        ans = 0
        
        for i in range(n):
            for j in range(m):
                ans += matrix[i][j]
                
        return ans