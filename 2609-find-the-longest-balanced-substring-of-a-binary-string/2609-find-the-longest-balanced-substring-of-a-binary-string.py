class Solution:
    def check(self, t):
        if t[0] == '1':
            return 0
        n = len(t)
        cntOne, cntZero = 0, 0
        for i in range(n):
            if t[i] == '0':
                cntZero += 1
            else:
                for j in range(i, n):
                    if t[j] == '1':
                        cntOne += 1
                        if cntOne == cntZero:
                            break
                    else:
                        break
                break
        
        return 2 * cntOne
    
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        n = len(s)
        sub = []
                
        for i in range(n + 1):
            for j in range(i + 1, n + 1):
                sub.append(s[i:j])
                
        ans = 0
        
        for t in sub:
            ans = max(ans, self.check(t))
            
        return ans