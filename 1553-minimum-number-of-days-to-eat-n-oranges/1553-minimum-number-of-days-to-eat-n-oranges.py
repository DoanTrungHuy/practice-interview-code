class Solution:
    def minDays(self, n: int) -> int:
        @lru_cache(None)
        def dp(n):
            if n == 0:
                return 0
            
            ans = 10**9
            
            if n % 2 == 0:
                ans = min(ans, 1 + dp(n - n / 2))
            
            if n % 3 == 0:
                ans = min(ans, 1 + dp(n - 2*(n / 3)))
                
            if n % 2 != 0 or n % 3 != 0:
                ans = min(ans, 1 + dp(n - 1))
                
            return ans
        
        return dp(n)