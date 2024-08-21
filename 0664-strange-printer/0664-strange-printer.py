class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        
        @lru_cache(None)
        def dp(l, r):
            if l > r:
                return 0
            
            ans = 1 + dp(l + 1, r)
            
            for k in range(l + 1, r + 1):
                if s[l] == s[k]:
                    ans = min(ans, dp(l + 1, k - 1) + dp(k, r))
                    
            return ans
        
        return dp(0, n - 1)