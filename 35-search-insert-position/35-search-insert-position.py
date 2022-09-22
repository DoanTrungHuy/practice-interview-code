class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        
        l, r = 0, n - 1
        ans = 0
        
        while l <= r:
            m = (l + r) >> 1
            
            if nums[m] < target:
                l = m + 1
                ans = l
            else:
                r = m - 1
                
        return ans