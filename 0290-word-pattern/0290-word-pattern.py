class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        m1 = defaultdict(int)
        m2 = defaultdict(int)
        n = len(pattern)
        s = s.split()
        
        if n != len(s):
            return False
        
        for i in range(n):
            if m1[pattern[i]] != m2[s[i]]:
                return False
            m1[pattern[i]] = i + 1
            m2[s[i]] = i + 1
            
        return True