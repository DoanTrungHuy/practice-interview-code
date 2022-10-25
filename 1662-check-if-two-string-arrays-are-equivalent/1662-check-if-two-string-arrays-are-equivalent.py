class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        s1, s2 = '', ''
        
        for word in word1:
            s1 += word
            
        for word in word2:
            s2 += word
            
        return s1 == s2