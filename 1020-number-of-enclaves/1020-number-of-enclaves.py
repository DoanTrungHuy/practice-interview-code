class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        def dfs(x: int, y: int) -> int:
            if not (0 <= x < n and 0 <= y < m and grid[x][y] == 1):
                return 0
            grid[x][y] = 0
            res = 1
            for i in range(4):
                res += dfs(x + dx[i], y + dy[i])
            return res
        
        cnt = 0
        
        for i in range(n):
            for j in range(m):
                cnt += grid[i][j]
        
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                        cnt -= dfs(i, j)
                    
        return cnt