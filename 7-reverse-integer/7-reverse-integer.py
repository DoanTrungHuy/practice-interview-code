class Solution:
    def reverse(self, x: int) -> int:
        front = [1, -1][x < 0]
        
        num = front * int(str(abs(x))[::-1])
        
        return num if -2**31 <= num <= 2**31 - 1 else 0
        