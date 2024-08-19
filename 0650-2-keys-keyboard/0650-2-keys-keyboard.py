class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        
        @lru_cache(None)
        def dp(v, c):
            if v > n:
                return 10**9
            
            if n == v:
                return 0
            
            return min(2 + dp(2*v, v), 1 + dp(v + c, c))
        
        return 1 + dp(1, 1)
    
    # 1
    # 2
    # 3
    # 4
    # 5
    # 6