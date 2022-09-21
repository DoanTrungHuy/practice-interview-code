class Solution:
    def check(self, n):
        n = str(n)
        l = 0
        r = len(n) - 1
        while l < r:
            if n[l] != n[r]:
                return False
            l += 1
            r -= 1
        return True
    
    def isStrictlyPalindromic(self, n: int) -> bool:
        for i in range(1, n + 1):
            if not self.check(bin(n)):
                return False
        return True