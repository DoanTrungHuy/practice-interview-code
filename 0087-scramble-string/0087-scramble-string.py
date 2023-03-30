class Solution:
    def __init__(self):
        self.dp = {}
        
    def isScramble(self, s1: str, s2: str) -> bool:
        n = len(s1)
        
        if s1 == s2:
            return True
        if n == 1:
            return False
        
        if (s1, s2) in self.dp:
            return self.dp[(s1, s2)]
        
        for i in range(1, n):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]) or \
            self.isScramble(s1[:i], s2[n - i:]) and self.isScramble(s1[i:], s2[:n - i]):
                self.dp[(s1, s2)] = True
                return True
            
        self.dp[(s1, s2)] = False
        
        return False