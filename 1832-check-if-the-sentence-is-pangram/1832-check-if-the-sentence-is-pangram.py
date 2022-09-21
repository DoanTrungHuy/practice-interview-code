class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        cnt = defaultdict(int)
        
        for char in sentence:
            cnt[char] += 1
            
        alpha = 'qwertyuiopasdfghjklzxcvbnm'
        
        for char in alpha:
            if cnt[char] == 0:
                return False
            
        return True