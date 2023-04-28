class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10**9 + 7
        n = len(s)
        
        @lru_cache(None)
        def dp(i):
            if i == n:
                return 1
            
            if s[i] == '0':
                return 0
            
            ans = 0
            num = 0
            
            for j in range(i, n):
                num = num*10 + (ord(s[j]) - ord('0'))
                if num > k:
                    break
                ans = (ans + dp(j + 1)) % MOD
                
            return ans
        
        return dp(0)