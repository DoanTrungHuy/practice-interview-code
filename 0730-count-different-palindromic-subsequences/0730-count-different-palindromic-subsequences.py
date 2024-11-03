class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        MOD = 10**9 + 7
        
        @lru_cache(None)
        def dp(l, r):
            if l > r:
                return 0
            
            ans = 0
            
            for c in "abcd":
                tl, tr = l, r
                
                while tl <= tr and s[tl] != c:
                    tl += 1
                    
                while tl <= tr and s[tr] != c:
                    tr -= 1
                    
                if tl > tr:
                    continue
                    
                ans = (ans + 1 + (tl != tr) + dp(tl + 1, tr - 1)) % MOD
                
            return ans
                
        return dp(0, len(s) - 1)