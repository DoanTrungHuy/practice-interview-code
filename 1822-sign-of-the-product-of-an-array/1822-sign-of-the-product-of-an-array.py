class Solution:
    def arraySign(self, nums: List[int]) -> int:
        pro = 1
        
        for num in nums:
            pro *= num
            
        if pro < 0:
            return -1
        elif pro > 0:
            return 1
        
        return 0