class Solution:
    def arraySign(self, nums: List[int]) -> int:
        cntNeg = 0
        
        for num in nums:
            if num == 0:
                return 0
            cntNeg += int(num < 0)
        
        return 1 if cntNeg % 2 == 0 else -1