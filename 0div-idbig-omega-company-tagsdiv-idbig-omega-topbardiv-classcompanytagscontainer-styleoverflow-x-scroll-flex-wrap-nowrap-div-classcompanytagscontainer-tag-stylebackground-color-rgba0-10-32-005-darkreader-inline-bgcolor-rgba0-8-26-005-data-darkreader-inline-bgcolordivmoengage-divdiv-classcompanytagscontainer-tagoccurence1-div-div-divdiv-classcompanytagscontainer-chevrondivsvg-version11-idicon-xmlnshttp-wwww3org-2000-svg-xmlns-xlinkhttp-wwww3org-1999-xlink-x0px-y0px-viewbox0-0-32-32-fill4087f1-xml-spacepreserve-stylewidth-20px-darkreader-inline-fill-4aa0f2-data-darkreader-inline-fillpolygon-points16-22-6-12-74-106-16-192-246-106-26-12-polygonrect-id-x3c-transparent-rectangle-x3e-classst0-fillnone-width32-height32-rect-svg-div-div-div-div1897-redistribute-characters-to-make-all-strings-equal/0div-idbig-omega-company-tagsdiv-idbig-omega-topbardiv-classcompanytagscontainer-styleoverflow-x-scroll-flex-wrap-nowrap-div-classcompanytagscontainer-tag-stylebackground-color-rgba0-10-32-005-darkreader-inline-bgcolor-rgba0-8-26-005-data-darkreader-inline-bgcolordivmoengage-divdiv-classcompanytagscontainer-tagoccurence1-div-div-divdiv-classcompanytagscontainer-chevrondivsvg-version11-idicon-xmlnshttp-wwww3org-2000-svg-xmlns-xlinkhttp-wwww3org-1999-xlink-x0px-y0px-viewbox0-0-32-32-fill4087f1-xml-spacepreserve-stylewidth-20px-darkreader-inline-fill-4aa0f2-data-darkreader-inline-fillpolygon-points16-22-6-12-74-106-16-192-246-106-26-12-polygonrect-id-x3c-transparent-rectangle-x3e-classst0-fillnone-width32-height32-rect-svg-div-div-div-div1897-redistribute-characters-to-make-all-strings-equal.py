class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = defaultdict(int)
        
        for word in words:
            for c in word:
                cnt[c] += 1
        
        N = len(words)
        
        for key, val in cnt.items():
            if val % N != 0:
                return False
            
        return True