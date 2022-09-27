class Solution:
    def arrangeCoins(self, n: int) -> int:
        row = 1
        
        while n > 0:
            row += 1
            n -= row
            
        return row - 1