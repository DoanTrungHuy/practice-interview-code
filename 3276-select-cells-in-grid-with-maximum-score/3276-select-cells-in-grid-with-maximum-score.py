class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        
        idx = defaultdict(list)
        
        for i in range(n):
            for j in range(m):
                idx[grid[i][j]].append(i)
                
        @lru_cache(None)
        def dp(val, mask):
            if val == 0:
                return 0
            
            ans = dp(val - 1, mask)
            
            for i in idx[val]:
                if mask & (1 << i):
                    continue
                ans = max(ans, val + dp(val - 1, mask | (1 << i)))
            
            return ans
        
        return dp(100, 0)