class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        pref, suff = 0, s.count('0')
        ans = n
        
        for c in s:
            suff -= c == '0'
            ans = min(ans, pref + suff)
            pref += c == '1'
            
        return ans