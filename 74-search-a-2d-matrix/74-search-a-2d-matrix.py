class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        # idx = r * m + c
        
        left, right = 0, row * col - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            element = matrix[mid // col][mid % col]
            
            if element == target:
                return True
            elif element < target:
                left = mid + 1
            else:
                right = mid - 1
                
        return False