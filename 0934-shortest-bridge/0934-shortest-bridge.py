class Solution:        
    def shortestBridge(self, grid: List[List[int]]) -> int:
        DIR = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        n = len(grid)
        
        def isValid(x: int, y: int) -> bool:
            return 0 <= x < n and 0 <= y < n
        
        dq = deque()
        
        def dfs(x: int, y: int) -> None:
            if not isValid(x, y) or grid[x][y] in (0, 2):
                return
            grid[x][y] = 2
            dq.append((x, y))
            for dx, dy in DIR:
                dfs(x + dx, y + dy)
                
        flag = False
        
        for x in range(n):
            for y in range(n):
                if grid[x][y] == 1 and not flag:
                    flag = True
                    dfs(x, y)
                    break
            if flag:
                break
        
        dist = 0
        
        while dq:
            sz = len(dq)
            
            for _ in range(sz):
                x, y = dq.popleft()
                
                for dx, dy in DIR:
                    nx = x + dx
                    ny = y + dy
                    if isValid(nx, ny):
                        if grid[nx][ny] == 1:
                            return dist
                        elif grid[nx][ny] == 0:
                            dq.append((nx, ny))
                            grid[nx][ny] = 2
            dist += 1
            
        return -1