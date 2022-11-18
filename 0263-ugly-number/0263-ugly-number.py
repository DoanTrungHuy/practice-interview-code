class Solution:
    def isPrime(self, n):
        if n < 2:
            return False
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def isUgly(self, n: int) -> bool:
        checkPrime = [2, 3, 5]
        
        for pr in checkPrime:
            if n % pr == 0:
                while n >= 1 and n % pr == 0:
                    n /= pr
                    
            if n not in checkPrime and self.isPrime(n):
                return False
            
            if n == 1:
                return True
            
        return False