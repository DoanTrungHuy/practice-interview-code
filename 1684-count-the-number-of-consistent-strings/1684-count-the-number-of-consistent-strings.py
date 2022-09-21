class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        cnt = 0
        
        for word in words:
            check = True
            
            for char in word:
                if char not in allowed:
                    check = False
                    break
            
            if check:
                cnt += 1
                
        return cnt