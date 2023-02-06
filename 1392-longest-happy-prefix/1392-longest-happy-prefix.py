class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        hl, hr = 0, 0
        pl = 1
        base, mod = 26, 1e9 + 7
        m = 0
        
        for i in range(n - 1):
            hl = (hl + (ord(s[i]) - ord('a') + 1)*pl) % mod
            pl = (pl*base) % mod
            
            hr = (hr*base + (ord(s[n - i - 1]) - ord('a') + 1)) % mod
            
            if hl == hr:
                m = i + 1
                
        return s[:m]