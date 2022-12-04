class Solution:
    def isCircularSentence(self, s: str) -> bool:
        if s[0] != s[-1]:
            return False
        
        n = len(s)
        
        for i in range(n - 1):
            if i and s[i] == ' ' and s[i - 1] != s[i + 1]:
                return False
            
        return True