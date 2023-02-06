class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        n = len(text)
        
        h = [0 for _ in range(n + 1)]
        p = [1 for _ in range(n + 1)]
        
        base, mod = 256, 10**9 + 7
        
        for i in range(1, n + 1):
            h[i] = (h[i - 1]*base + ord(text[i - 1])) % mod
            p[i] = (p[i - 1]*base) % mod
            
        def getHash(l: int, r: int) -> int:
            return (h[r] - h[l - 1]*p[r - l + 1] - mod*mod) % mod
        
        s = set()
            
        for i in range(0, n):
            j = 2
            while i + j <= n:
                m = i + j // 2
                lval = getHash(i + 1, m);
                rval = getHash(m + 1, i + j)
                if lval == rval:
                    s.add(lval)
                j += 2
                
        return len(s)