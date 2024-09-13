class Solution:
    def convertDateToBinary(self, date: str) -> str:
        y, m, d = map(int, date.split('-'))
        y, m, d = bin(y)[2:], bin(m)[2:], bin(d)[2:]
        
        return y + '-' + m + '-' + d