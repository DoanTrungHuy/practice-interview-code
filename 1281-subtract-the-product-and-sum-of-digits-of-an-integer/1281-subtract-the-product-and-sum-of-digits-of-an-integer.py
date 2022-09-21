class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        s, p = 0, 1
        
        while n > 0:
            num = n % 10
            s += num
            p *= num
            n //= 10
            
        return p - s