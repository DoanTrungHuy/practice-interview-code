class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n, m = len(s1), len(s2)
        
        if n > m:
            return False
        
        cntStr1, cntStr2 = [0] * 26, [0] * 26
        
        for i in range(n):
            cntStr1[ord(s1[i]) - ord('a')] += 1
            cntStr2[ord(s2[i]) - ord('a')] += 1
        
        if cntStr1 == cntStr2:
            return True
        
        for i in range(n, m):
            cntStr2[ord(s2[i - n]) - ord('a')] -= 1
            cntStr2[ord(s2[i]) - ord('a')] += 1
            if cntStr1 == cntStr2:
                return True
            
        return False