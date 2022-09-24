class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        i, j = 0, m - 1
        
        while i < n and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        
        return False