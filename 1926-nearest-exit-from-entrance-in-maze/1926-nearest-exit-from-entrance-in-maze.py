class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        dq = deque()
        x, y = entrance
        
        dq.append((x, y))
        maze[x][y] = '+'
        
        n, m = len(maze), len(maze[0])
        
        def isValid(x: int, y: int) -> bool:
            return 0 <= x < n and 0 <= y < m
        
        dist = 0
        
        while dq:
            sz = len(dq)
            
            for _ in range(sz):
                x, y = dq.popleft()
                
                for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                    nx = x + dx
                    ny = y + dy
                    
                    if isValid(nx, ny):
                        if maze[nx][ny] != '+':
                            maze[nx][ny] = '+'
                            dq.append((nx, ny))
                    else:
                        if dist == 0:
                            continue
                        return dist
                    
            dist += 1
            
        
        return -1