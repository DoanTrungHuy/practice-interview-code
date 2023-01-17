class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        pref, suff = [0] * (n + 2), [0] * (n + 2)
        ans = inf
        
        for i in range(1, n + 1):
            pref[i] = pref[i - 1] + (s[i - 1] == '1')
            
        for i in range(n, 0, -1):
            suff[i] = suff[i + 1] + (s[i - 1] == '0')
            
        for i in range(1, n + 2):
            ans = min(ans, pref[i - 1] + suff[i])
            
        return ans