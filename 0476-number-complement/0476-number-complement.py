class Solution:
    def findComplement(self, num: int) -> int:
        ans = 0 
        i = 0
        while num:
            ans |= (num & 1 ^ 1) << i
            num >>= 1
            i += 1
        return ans