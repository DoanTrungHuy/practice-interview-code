class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        cnt = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] < 0:
                    cnt += 1
                    
        return cnt