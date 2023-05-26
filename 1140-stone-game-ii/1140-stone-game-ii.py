class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        
        @lru_cache(None)
        def dp(alice, i, M):
            if i == n:
                return 0
            
            res = 0 if alice else float(inf)
            total = 0
            
            for X in range(1, 2*M + 1):
                if i + X - 1 == n:
                    break
                total += piles[i + X - 1]
                if alice:
                    res = max(res, total + dp(not alice, i + X, max(X, M)))
                else:
                    res = min(res, dp(not alice, i + X, max(X, M)))
                    
            return res
        
        return dp(True, 0, 1)