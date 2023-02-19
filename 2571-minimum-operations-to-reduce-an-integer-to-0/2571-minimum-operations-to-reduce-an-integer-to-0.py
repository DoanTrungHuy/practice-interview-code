class Solution:
    def minOperations(self, n: int) -> int:
        if n == 0:
            return 0
        x = int(floor(log2(n)))
        y = int(ceil(log2(n)))
        
        op1 = abs(pow(2, x) - n)
        op2 = abs(pow(2, y) - n)
        
        print(x, y)
        
        if op1 > op2:
            return 1 + self.minOperations(op2)
        return 1 + self.minOperations(op1)