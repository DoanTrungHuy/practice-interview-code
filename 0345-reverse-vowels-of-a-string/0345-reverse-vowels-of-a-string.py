class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        n = len(s)
        s = list(s)
        i, j = 0, n - 1
        
        while i < j:
            if s[i] in vowels and s[j] in vowels:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1
            elif s[i] not in vowels:
                i += 1
            else:
                j -= 1
                
        return ''.join(s)