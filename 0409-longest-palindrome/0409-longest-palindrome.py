class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = [0 for _ in range(256)]
        
        for c in s:
            cnt[ord(c)] += 1
        
        res = 0
        odd = False
        
        for i in range(256):
            if cnt[i] % 2 == 0:
                res += cnt[i]
            else:
                res += cnt[i] - 1
                odd = True
                
        return res + int(odd)