class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        DIR = [1, 0, -1, 0, 1]
        n, m = len(grid), len(grid[0])
        self.cnt = 0
        
        def dfs(x: int, y: int, empty: int) -> None:
            if not (0 <= x < n and 0 <= y < m and grid[x][y] != -1):
                return
            if grid[x][y] == 2:
                self.cnt += empty == 0
                return
            grid[x][y] = -1
            for i in range(4):
                dfs(x + DIR[i], y + DIR[i + 1], empty - 1)
            grid[x][y] = 0
            
        x, y, empty = 0, 0, 1
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    x, y = i, j
                elif grid[i][j] == 0:
                    empty += 1
                    
        dfs(x, y, empty)
        return self.cnt