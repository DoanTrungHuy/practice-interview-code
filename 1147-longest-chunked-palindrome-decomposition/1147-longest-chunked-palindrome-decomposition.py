class Solution:
    def longestDecomposition(self, text: str) -> int:
        lh, rh = 0, 0
        n = len(text)
        mod = 10**9 + 7
        lp = 1
        base = 26
        ans = 0
        
        for i in range(n):
            lh = (lh + (ord(text[i]) - ord('a') + 1) * lp) % mod
            lp = (lp * base) % mod
            j = n - i - 1
            rh = (rh * base + (ord(text[j]) - ord('a') + 1)) % mod
            if lh == rh:
                ans += 2
                lh, rh = 0, 0
                lp = 1
        
        return ans // 2