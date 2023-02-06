class Solution:
    def shortestPalindrome(self, s: str) -> str:
        oh, rh = 0, 0
        op = 1
        base, mod = 26, 10**9 + 13
        sp = 0
        n = len(s)
        
        for i in range(n):
            oh = (oh + (ord(s[i]) - ord('a') + 1)*op) % mod
            op = (op*base) % mod
            
            rh = (rh*base + (ord(s[i]) - ord('a') + 1)) % mod
            
            if oh == rh:
                sp = i
                
        return s[sp + 1:][::-1] + s