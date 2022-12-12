class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # "abcabcbb"
        #    ^^^
        # "pwwkew"
        
        maxLen = 0
        setChr = set()
        j = 0
        n = len(s)
        for i in range(n):
            while s[i] in setChr:
                setChr.discard(s[j])
                j += 1
            setChr.add(s[i])
            maxLen = max(maxLen, len(setChr))
            
        return maxLen