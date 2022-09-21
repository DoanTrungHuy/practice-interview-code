class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        maxSpace = 0
        
        for string in sentences:
            maxSpace = max(maxSpace, string.count(' ') + 1)
            
        return maxSpace