class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row = {
            0: "qwertyuiop",
            1: "asdfghjkl",
            2: "zxcvbnm"
        }
        
        flag = -1
        answ = []
        
        for word in words:
            if word[0].lower() in row[0]:
                flag = 0
            elif word[0].lower() in row[1]:
                flag = 1
            else:
                flag = 2
                
            check = True
            
            for char in word:
                if char.lower() not in row[flag]:
                    check = False
                    break
            
            if check:
                answ.append(word)
                
        return answ