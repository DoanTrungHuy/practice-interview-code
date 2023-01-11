class Solution:
    def __init__(self):
        self.components = [[]]
        self.size = dict()
        self.n = 0
        self.DIR = [1, 0, -1, 0, 1]
        self.grid = [[]]
        
    def isValid(self, r: int, c: int) -> bool:
        return 0 <= r < self.n and 0 <= c < self.n
        
    def dfs(self, r: int, c: int, flag: int) -> None:
        self.components[r][c] = flag
        self.size[flag] += 1
        for d in range(4):
            nr = r + self.DIR[d]
            nc = c + self.DIR[d + 1]
            if self.isValid(nr, nc) and self.grid[nr][nc] and self.components[nr][nc] == -1:
                self.dfs(nr, nc, flag)
        
    def largestIsland(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.grid = grid
        self.components = [[-1 for _ in range(self.n)] for _ in range(self.n)]
        flag = 0
        
        for r in range(self.n):
            for c in range(self.n):
                if self.grid[r][c] and self.components[r][c] == -1:
                    self.size[flag] = 0
                    self.dfs(r, c, flag)
                    print(self.size[flag])
                    flag += 1
                    
        ans = 0
        
        for r in range(self.n):
            for c in range(self.n):
                if not self.grid[r][c]:
                    save = set()
                    for d in range(4):
                        nr = r + self.DIR[d]
                        nc = c + self.DIR[d + 1]
                        if self.isValid(nr, nc) and self.grid[nr][nc] == 1:
                            save.add(self.components[nr][nc])
                            
                    total = 1
                    for flag in save:
                        total += self.size[flag]
                        
                    ans = max(ans, total)
                    
        return self.n * self.n if not ans else ans
                