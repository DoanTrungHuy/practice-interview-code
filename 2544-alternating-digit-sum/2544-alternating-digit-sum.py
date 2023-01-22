class Solution:
    def alternateDigitSum(self, n: int) -> int:
        answ = 0
        flag = False
        
        if len(str(n)) & 1:
            flag = True
        
        while n > 0:
            d = n % 10
            if flag:
                answ += d
                flag = False
            else:
                answ -= d
                flag = True
            n //= 10
            
        return answ