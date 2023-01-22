class Solution:
    def alternateDigitSum(self, n: int) -> int:
        answ = 0
        sign = -1
        
        if len(str(n)) & 1:
            sign = 1
        
        while n > 0:
            d = sign * (n % 10)
            answ += d
            n //= 10
            sign *= -1
            
        return answ