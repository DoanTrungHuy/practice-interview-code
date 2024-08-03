class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:
        n = len(s)
        ans = 0
        s = list(s)
        
        for i in range(n):
            flag = False
            j = 0
            while j < n - 1:
                if s[j] == '0' and s[j + 1] == '1':
                    s[j], s[j + 1] = s[j + 1], s[j]
                    flag = True
                    j += 1
                j += 1
                
            if not flag:
                break
                
            ans += flag
        
        return ans