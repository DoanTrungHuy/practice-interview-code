class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        k = len(needle)
        
        for i in range(n - k + 1):
            if haystack[i:k + i] == needle:
                return i
            
        return -1