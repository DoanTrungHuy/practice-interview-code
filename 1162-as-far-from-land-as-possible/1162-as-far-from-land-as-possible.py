class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dq = deque()
        
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    dq.append((i, j))
        
        if len(dq) == n*n:
            return -1
        
        res = 0
        
        while dq:
            m = len(dq)
            res += 1
            for _ in range(m):
                i, j = dq.popleft()
                di = [-1, 1, 0, 0]
                dj = [0, 0, -1, 1]
                for c in range(4):
                    ni = i + di[c]
                    nj = j + dj[c]
                    if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] == 0:
                        dq.append((ni, nj))
                        grid[ni][nj] = 1
                        
        return res - 1