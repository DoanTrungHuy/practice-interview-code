class Solution:
    def isReachable(self, x: int, y: int) -> bool:
        while x % 2 == 0:
            x //= 2
        while y % 2 == 0:
            y //= 2
        return gcd(x, y) == 1