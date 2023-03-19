class Solution:  
    def __init__(self):
        self.n = 0
        
    def helper(self, s, i, j):
        cnt = 0
        while i >= 0 and j < self.n and s[i] == s[j]:
            i -= 1
            j += 1
            cnt += 1
        return cnt
    
    def countSubstrings(self, s: str) -> int:
        self.n = len(s)
        ans = 0
        
        for i in range(self.n):
            ans += self.helper(s, i, i)
            ans += self.helper(s, i, i + 1)
        
        return ans