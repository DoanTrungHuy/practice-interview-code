class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.upper() == word or word.lower() == word:
            return True
        
        n = len(word)
        if n >= 1 and word[0].upper() != word[0]:
            return False
        
        for i in range(1, n):
            if word[i].lower() != word[i]:
                return False
                
        return True