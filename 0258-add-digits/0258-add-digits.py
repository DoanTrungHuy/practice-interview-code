class Solution:
    def addDigits(self, num: int) -> int:
        total = num
        
        while num >= 10:
            total = sum(map(int, str(num)))
            num = total
            
        return total