class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        setChr = set()
        n = len(s)
        j = 0
        
        for i in range(n):
            while s[i] in setChr:
                setChr.discard(s[j])
                j += 1
            setChr.add(s[i])
            maxLen = max(maxLen, len(setChr))
            
        return maxLen