class Solution:
    def check(self, hm):
        s = set()
        for key in hm:
            if hm[key] > 0:
                s.add(hm[key])
        if len(s) == 1:
            return True
        return False
    
    def equalFrequency(self, word: str) -> bool:
        hm = Counter(word)
        s = set()
        for key in hm:
            hm[key] -= 1
            if self.check(hm):
                return True
            hm[key] += 1
            
        return False