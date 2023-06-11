class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n <= 2:
            return -1
        
        ma = max(nums)
        mi = min(nums)
        
        for num in nums:
            if num != mi and num != ma:
                return num
            
        return -1