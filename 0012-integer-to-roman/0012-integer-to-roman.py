class Solution:
    def intToRoman(self, num: int) -> str:
        val = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        sym = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        
        i = 0
        ans = ''
        
        while i < 13 and num > 0:
            while num >= val[i]:
                ans += sym[i]
                num -= val[i]
            i += 1
            
        return ans