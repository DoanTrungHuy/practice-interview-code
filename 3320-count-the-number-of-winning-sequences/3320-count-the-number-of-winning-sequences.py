class Solution:
    def countWinningSequences(self, s: str) -> int:
        n = len(s)
        MOD = 10**9 + 7
        mp = {'F': 'W', 'W': 'E', 'E': 'F'}
        
        @lru_cache(None)
        def dp(i, lm, sd):
            if i == n:
                return sd > 0
            
            ans = 0
            
            for bm in 'FWE':
                if bm == lm:
                    continue 
                
                n_sc = 0
                
                if bm == mp[s[i]]:
                    n_sc += 1  
                elif mp[bm] == s[i]:
                    n_sc -= 1 

                ans = (ans + dp(i + 1, bm, n_sc + sd)) % MOD
            
            return ans

        return dp(0, None, 0)