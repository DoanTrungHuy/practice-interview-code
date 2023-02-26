class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        s = 0
        ans = []
        
        for c in word:
            s = (s * 10 + ord(c) - ord('0')) % m
            ans.append(int(s % m == 0))
            
        return ans