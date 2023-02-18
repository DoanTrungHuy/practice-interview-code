class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        nums.sort()
        i = 1
        
        while True:
            if nums.count(i) == 0:
                return i
            i *= 2
        
        return -1