class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        mod = 10**9 + 7
        base = 2
        n = len(s)
        h = [0 for _ in range(n + 1)]
        p = [1 for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            h[i] = (h[i - 1]*base + ord(s[i - 1])) % mod
            p[i] = (p[i - 1]*base) % mod
            
        cs = set()
        
        for i in range(1, n - k + 2):
            l = i
            r = i + k - 1
            cs.add((h[r] - h[l - 1]*p[r - l + 1] + mod*mod) % mod)
            
        return len(cs) == 1 << k