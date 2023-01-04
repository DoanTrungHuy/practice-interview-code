class Solution:
    def rotatedDigits(self, n: int) -> int:
        c1 = set([0, 1, 8])
        c2 = set([0, 1, 8, 2, 5, 6, 9])
        
        def isGood(x):
            s = set([int(i) for i in str(x)])
            return s.issubset(c2) and not s.issubset(c1)
        
        return sum([isGood(i) for i in range(n + 1)])