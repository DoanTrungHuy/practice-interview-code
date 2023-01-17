class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        n, m = len(grid), len(grid[0])
        
        def dfs(x: int, y: int) -> bool:
            if not (0 <= x and x < n and 0 <= y < m):
                return False
            
            if grid[x][y] == 1:
                return True
            
            grid[x][y] = 1
            check = True
            for i in range(4):
                check &= dfs(x + dx[i], y + dy[i])
            return check
        
        ans = 0
        
        for x in range(n):
            for y in range(m):
                if grid[x][y] == 0:
                    ans += dfs(x, y)
        
        return ans