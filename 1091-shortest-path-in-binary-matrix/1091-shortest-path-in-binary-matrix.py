class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        DIR = []
        n = len(grid)
        
        for x in [-1, 0, 1]:
            for y in [-1, 0, 1]:
                DIR.append([x, y])
                
        DIR.remove([0, 0])
        
        dq = deque()
        
        if grid[0][0] == 0:
            dq.append((0, 0, 1))
            grid[0][0] = 1
        
        while dq:
            x, y, d = dq.popleft()
            
            if x == n - 1 and y == n - 1:
                return d
            
            for dx, dy in DIR:
                nx = x + dx
                ny = y + dy
                
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 0:
                    grid[nx][ny] = 1
                    dq.append((nx, ny, d + 1))

        return -1