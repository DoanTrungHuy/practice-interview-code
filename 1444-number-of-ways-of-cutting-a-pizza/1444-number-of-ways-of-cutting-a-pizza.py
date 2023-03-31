class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        n, m = len(pizza), len(pizza[0])
        mod = 10**9 + 7
        
        p = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            s = 0
            for j in range(1, m + 1):
                s += int(pizza[i - 1][j - 1] == 'A')
                p[i][j] = p[i - 1][j] + s
        
        def count(r1, c1, r2, c2):
            return p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1]
        
        dp = {}
        
        def dfs(i, j, k):
            if k == 1:
                return int(count(i + 1, j + 1, n, m) >= 1)
            
            if (i, j, k) in dp:
                return dp[(i, j, k)]
            
            ans = 0
            
            for r in range(i + 1, n):
                if count(i + 1, j + 1, r, m) >= 1:
                    ans += dfs(r, j, k - 1) % mod
                    
            for c in range(j + 1, m):
                if count(i + 1, j + 1, n, c) >= 1:
                    ans += dfs(i, c, k - 1) % mod
                    
            dp[(i, j, k)] = ans % mod
            
            return dp[(i, j, k)]
        
        return dfs(0, 0, k)
        