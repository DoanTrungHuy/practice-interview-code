class Solution:
    @cache
    def isScramble(self, s1: str, s2: str) -> bool:
        n = len(s1)
        
        if s1 == s2:
            return True
        if n == 1:
            return False
        
        for i in range(1, n):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[n - i:]) and self.isScramble(s1[i:], s2[:n - i]):
                return True
            
        return False