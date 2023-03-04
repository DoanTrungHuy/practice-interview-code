class Solution:
    def splitNum(self, num: int) -> int:
        s = ''.join(sorted(list(str(num))))
        n = len(s)
        
        num1, num2 = '', ''
    
        for i in range(0, n, 2):
            num1 += s[i]
            
        for i in range(1, n, 2):
            num2 += s[i]
            
        return int(num1) + int(num2)