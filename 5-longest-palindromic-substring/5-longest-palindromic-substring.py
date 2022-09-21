class Solution:
    def helper(self, s, i, j):
        while i >= 0 and j < self.n and s[i] == s[j]:
            i -= 1
            j += 1
        return s[i + 1: j]
    
    def longestPalindrome(self, s: str) -> str:
        self.n = len(s)
        ans = ""
        
        for i in range(0, self.n):
            s1 = self.helper(s, i, i)
            s2 = self.helper(s, i, i + 1)
            
            if len(s1) > len(s2):
                s2 = s1
                
            if len(ans) < len(s2):
                ans = s2
                
        return ans