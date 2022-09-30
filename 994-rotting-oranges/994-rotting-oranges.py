class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        step = 0
        r, c = len(grid), len(grid[0])
        dq = deque()
        cntFresh = 0
        
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 2:
                    dq.append((i, j))
                elif grid[i][j] == 1:
                    cntFresh += 1
                    
        DIR = [-1, 0, 1, 0, -1]
                    
        while dq and cntFresh > 0:
            n = len(dq)
            
            for _ in range(n):
                x, y = dq.popleft()
                for i in range(4):
                    xx = x + DIR[i]
                    yy = y + DIR[i + 1]
                    if 0 <= xx < r and 0 <= yy < c and grid[xx][yy] == 1:
                        dq.append((xx, yy))
                        grid[xx][yy] = 2
                        cntFresh -= 1
            
            step += 1
            
        return -1 if cntFresh != 0 else step