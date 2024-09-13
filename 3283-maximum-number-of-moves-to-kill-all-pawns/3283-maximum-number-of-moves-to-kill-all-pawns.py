class Solution:
    DIR = [
        (1, 2), (1, -2), (-1, 2), (-1, -2),
        (2, 1), (2, -1), (-2, 1), (-2, -1)
    ]
    
    def __init__(self):
        self.p = []
        self.dist = []
        
    @lru_cache(None)
    def bfs(self, kx: int, ky: int, tx: int, ty: int) -> int:
        if kx == tx and ky == ty:
            return 0
        
        vis = [[False] * 50 for _ in range(50)]
        vis[kx][ky] = True
        mq = deque([(kx, ky, 0)])
        
        while mq:
            x, y, m = mq.popleft()
            
            for dx, dy in self.DIR:
                nx, ny = x + dx, y + dy
                
                if nx == tx and ny == ty:
                    return m + 1
                
                if 0 <= nx < 50 and 0 <= ny < 50 and not vis[nx][ny]:
                    vis[nx][ny] = True
                    mq.append((nx, ny, m + 1))
        
        return -1
    
    @lru_cache(None)
    def dp(self, knp: int, mask: int, is_alice: bool) -> int:
        n = len(self.p)
        ans, flag = float('-inf') if is_alice else float('inf'), False
        
        for i in range(n):
            if (mask & (1 << i)) == 0:
                m = self.dist[knp][i + 1]
                flag = True

                nm = self.dp(i + 1, mask | (1 << i), not is_alice)

                if is_alice:
                    ans = max(ans, m + nm)
                else:
                    ans = min(ans, m + nm)
        
        if not flag:
            return 0
        
        return ans
    
    def maxMoves(self, kx: int, ky: int, p: List[List[int]]) -> int:
        self.p = p
        n = len(p)
        self.dist = [[0] * (n + 1) for _ in range(n + 1)]
        
        for i in range(n):
            self.dist[i + 1][0] = self.dist[0][i + 1] = self.bfs(kx, ky, p[i][0], p[i][1])
        
        for i in range(n):
            for j in range(i + 1, n):
                self.dist[i + 1][j + 1] = self.dist[j + 1][i + 1] = self.bfs(p[i][0], p[i][1], p[j][0], p[j][1])
        
        return self.dp(0, 0, True)
