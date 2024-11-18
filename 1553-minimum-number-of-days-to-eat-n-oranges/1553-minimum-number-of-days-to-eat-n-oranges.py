class Solution:
    def minDays(self, n: int) -> int:
        @lru_cache(None)
        def dp(n):
            if n <= 1:
                return n
            
            ans = 10**9
            
            ans = min(ans, 1 + n % 3 + dp(n // 3))
            ans = min(ans, 1 + n % 2 + dp(n // 2))
                
            return ans
        
        return dp(n)
