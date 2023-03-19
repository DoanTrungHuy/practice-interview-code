class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        DIR = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
        n = len(grid)
        self.check = False
        oo = 1000
        
        def dfs(x, y, step):
            for dx, dy in DIR:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == step:
                    grid[nx][ny] = oo
                    dfs(nx, ny, step + 1)
                    break
            
        dfs(0, 0, 1)
        
        cnt = 0
        
        for x in grid:
            for y in x:
                cnt += (y == oo)
        
        return cnt == (n * n - 1)
        