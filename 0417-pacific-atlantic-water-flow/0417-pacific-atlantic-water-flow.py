class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        
        pacific = [[False for _ in range(205)] for _ in range(205)]
        
        atlantic = [[False for _ in range(205)] for _ in range(205)]
        
        def dfs1(x: int, y: int) -> None:
            pacific[x][y] = True
            for dx, dy in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m and heights[x][y] <= heights[nx][ny] and not pacific[nx][ny]:
                    dfs1(nx, ny)
                    
        def dfs2(x: int, y: int) -> None:
            atlantic[x][y] = True
            for dx, dy in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                nx = x + dx
                ny = y + dy
                if 0 <= nx < n and 0 <= ny < m and heights[x][y] <= heights[nx][ny] and not atlantic[nx][ny]:
                    dfs2(nx, ny)
                    
        for i in range(n):
            dfs1(i, 0)
            dfs2(i, m - 1)
            
        for j in range(m):
            dfs1(0, j)
            dfs2(n - 1, j)
            
        ans = []
            
        for i in range(n):
            for j in range(m):
                if pacific[i][j] & atlantic[i][j]:
                    ans.append([i, j])
                    
        return ans