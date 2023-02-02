class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            cntBit1 = 0
            for num in nums:
                if (num >> i) & 1:
                    cntBit1 += 1
            cntBit1 %= 3
            if cntBit1:
                ans |= 1 << i
               
        return ans - (1 << 32) if ans > (1 << 31) - 1 else ans