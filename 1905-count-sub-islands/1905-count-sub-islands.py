class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        n, m = len(grid2), len(grid2[0])
        
        def dfs(x: int, y: int) -> int:
            if not (0 <= x < n and 0 <= y < m and grid2[x][y] == 1):
                return 1
            res = 1
            grid2[x][y] = 0
            for dx, dy in [[-1, 0], [0, -1], [0, 1], [1, 0]]:
                res &= dfs(x + dx, y + dy)
            return res & grid1[x][y]
                    
        return sum([dfs(x, y) for x in range(n) for y in range(m) if grid2[x][y]])