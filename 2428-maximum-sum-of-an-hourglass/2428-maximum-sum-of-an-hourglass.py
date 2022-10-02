class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxTotal = 0
        
        for i in range(m - 2):
            for j in range(n - 2):
                maxTotal = max(maxTotal, sum(grid[i][j:j + 3]) + grid[i + 1][j + 1] + sum(grid[i + 2][j:j + 3]))
                
        return maxTotal