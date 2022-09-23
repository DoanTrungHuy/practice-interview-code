class Solution:
    def concatenatedBinary(self, n: int) -> int:
        binNum = ''
        
        for i in range(1, n + 1):
            binNum += bin(i)[2:]
            
        return int(binNum, 2) % (10**9 + 7)