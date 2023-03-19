class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        b = bin(n)[2:][::-1]
        
        print(b)
        
        cntOdd, cntEven = 0, 0
        
        for i in range(len(b)):
            if b[i] == '1' and i % 2 == 0:
                cntEven += 1
            if b[i] == '1' and i % 2 != 0:
                cntOdd += 1
                
        return [cntEven, cntOdd]