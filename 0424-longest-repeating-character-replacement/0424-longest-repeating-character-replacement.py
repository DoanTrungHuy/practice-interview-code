class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        j = 0
        maxFreq, maxLeng = 0, 0
        d = defaultdict(int)
        
        for i in range(n):
            d[s[i]] += 1
            maxFreq = max(maxFreq, d[s[i]])
            if i - j + 1 - maxFreq > k:
                d[s[j]] -= 1
                j += 1
            maxLeng = max(maxLeng, i - j + 1)
        
        return maxLeng