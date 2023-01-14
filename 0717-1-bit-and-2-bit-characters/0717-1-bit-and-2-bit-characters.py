class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        
        if bits[n - 1] != 0:
            return False
        
        i = 0
        while i < n:
            if i == n - 1:
                return True
            if bits[i] == 1:
                i += 2
            else:
                i += 1
                
        return False