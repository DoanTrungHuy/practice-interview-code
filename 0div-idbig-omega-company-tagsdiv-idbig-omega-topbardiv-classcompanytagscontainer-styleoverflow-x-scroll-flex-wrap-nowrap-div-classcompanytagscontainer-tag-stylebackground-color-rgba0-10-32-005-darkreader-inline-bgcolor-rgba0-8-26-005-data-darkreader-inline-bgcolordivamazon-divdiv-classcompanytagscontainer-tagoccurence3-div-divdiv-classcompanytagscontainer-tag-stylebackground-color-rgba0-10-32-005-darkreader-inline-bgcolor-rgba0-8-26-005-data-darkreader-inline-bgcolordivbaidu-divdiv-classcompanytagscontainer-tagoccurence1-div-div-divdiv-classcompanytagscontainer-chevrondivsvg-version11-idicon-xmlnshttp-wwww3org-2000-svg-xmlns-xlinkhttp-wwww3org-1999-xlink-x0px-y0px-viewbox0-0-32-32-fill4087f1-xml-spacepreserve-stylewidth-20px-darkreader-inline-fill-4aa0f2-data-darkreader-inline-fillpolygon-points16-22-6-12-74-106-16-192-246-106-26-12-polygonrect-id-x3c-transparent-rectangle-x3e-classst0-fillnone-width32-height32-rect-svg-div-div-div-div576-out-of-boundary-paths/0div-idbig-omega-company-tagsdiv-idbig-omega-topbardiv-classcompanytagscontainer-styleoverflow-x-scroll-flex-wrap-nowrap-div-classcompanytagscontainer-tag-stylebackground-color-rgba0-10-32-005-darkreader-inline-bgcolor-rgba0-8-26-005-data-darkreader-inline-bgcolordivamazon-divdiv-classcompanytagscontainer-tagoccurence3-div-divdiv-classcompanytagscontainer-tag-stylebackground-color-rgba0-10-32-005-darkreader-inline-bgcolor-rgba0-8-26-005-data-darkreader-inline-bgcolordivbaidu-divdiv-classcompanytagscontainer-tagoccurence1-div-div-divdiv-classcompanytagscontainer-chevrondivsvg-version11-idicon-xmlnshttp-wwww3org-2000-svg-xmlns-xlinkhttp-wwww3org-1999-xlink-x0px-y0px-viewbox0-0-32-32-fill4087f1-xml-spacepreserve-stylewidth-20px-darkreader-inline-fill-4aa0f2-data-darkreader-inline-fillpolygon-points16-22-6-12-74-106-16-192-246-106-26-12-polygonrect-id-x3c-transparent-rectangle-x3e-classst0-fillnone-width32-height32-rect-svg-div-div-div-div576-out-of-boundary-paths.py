class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        DIR = [[-1, 0], [0, -1], [0, 1], [1, 0]]
        MOD = 10**9 + 7
        
        @lru_cache(None)
        def dfs(i, j, move):
            if not (0 <= i < m and 0 <= j < n):
                return 1
            
            ans = 0
            for di, dj in DIR:
                ni = i + di
                nj = j + dj
                if move > 0:
                    ans = (ans + dfs(ni, nj, move - 1)) % MOD
                
            return ans
        
        return dfs(startRow, startColumn, maxMove)