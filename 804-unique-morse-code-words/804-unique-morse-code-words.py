class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        trans = [".-","-...","-.-.","-..",".",
                 "..-.","--.","....","..",".---","-.-",
                 ".-..","--","-.","---",".--.","--.-",".-.",
                 "...","-","..-","...-",".--","-..-","-.--","--.."]
        
        hashSet = set()
        
        for word in words:
            temp = ""
            for char in word:
                temp += trans[ord(char) - ord('a')]
            
            hashSet.add(temp)
            
        return len(hashSet)