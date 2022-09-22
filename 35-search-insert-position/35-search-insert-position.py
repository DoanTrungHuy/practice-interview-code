class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:    
        n = len(nums)
        l, r = 0, n - 1
        res = n
        
        while l <= r:
            m = (l + r) >> 1
            
            if nums[m] >= target:
                res = m
                r = m - 1
            else:
                l = m + 1
                
        return res