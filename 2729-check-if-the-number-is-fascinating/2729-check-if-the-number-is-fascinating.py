class Solution:
    def isFascinating(self, n: int) -> bool:
        t = list(str(n) + str(2*n) + str(3*n))
        t.sort()
        t = ''.join(t)
        return '123456789' == t