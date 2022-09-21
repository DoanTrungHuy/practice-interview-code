class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        n, m = len(grid), len(grid[0])
        
        def dfs(x: int, y: int) -> int:
            if x < 0 or x == n or y < 0 or y == m or grid[x][y] == 0:
                return 0
            grid[x][y] = 0
            return 1 + dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y + 1) + dfs(x, y - 1)
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, dfs(i, j))
                    
        return maxArea