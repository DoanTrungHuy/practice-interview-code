class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        grid: List[List[int]] = [[0 for _ in range(n)] for _ in range(m)]
        
        for cell in indices:
            x: int = cell[0]
            y: int = cell[1]
            for i in range(m):
                grid[i][y] += 1
            for j in range(n):
                grid[x][j] += 1
                
        ans: int = 0
        
        for i in range(m):
            for j in range(n):
                ans += grid[i][j] & 1
                
        return ans