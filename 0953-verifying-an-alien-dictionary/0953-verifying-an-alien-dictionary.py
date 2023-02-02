class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        n = len(words)
        h = {}
        
        for i, char in enumerate(order):
            h[char] = chr(i + ord('a'))
            
        words = [[h[char] for char in word] for word in words]
        
        for word1, word2 in zip(words, words[1:]):
            if word1 > word2:
                return False
            
        return True
        