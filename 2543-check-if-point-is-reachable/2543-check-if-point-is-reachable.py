class Solution:
    def isReachable(self, targetX: int, targetY: int) -> bool:
        tx, ty = targetX, targetY
        while tx & 1 == 0:
            tx >>= 1
        while ty & 1 == 0:
            ty >>= 1
        g = math.gcd(tx, ty)
        if g == 1:
            return True
        else:
            return False
