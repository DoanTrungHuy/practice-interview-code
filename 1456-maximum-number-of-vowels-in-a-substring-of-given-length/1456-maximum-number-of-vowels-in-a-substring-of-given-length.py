class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        l: int = 0
        n: int = len(s)
        cnt: int = 0
        vowel: str = "ueoai"
        ans: int = 0
        
        for r in range(n):
            cnt += int(s[r] in vowel)
            
            if r - l + 1 > k:
                cnt -= int(s[l] in vowel)
                l += 1
                
            ans = max(ans, cnt)
        
        return ans