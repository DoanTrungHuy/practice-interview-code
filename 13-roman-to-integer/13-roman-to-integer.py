class Solution:
    def romanToInt(self, s: str) -> int:
        hashMap = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        n = len(s)
        ans = 0
        
        for i in range(0, n):
            if i + 1 < n and hashMap[s[i]] < hashMap[s[i + 1]]:
                ans -= hashMap[s[i]]
            else:
                ans += hashMap[s[i]]
            
        return ans