class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        if n == 2:
            return 0 if nums[0] > nums[1] else 1
        l = 0
        r = n - 2
        ans = 0
        
        while l <= r:
            m = (l + r) // 2
            
            if nums[m] < nums[m + 1]:
                ans = m + 1
                l = m + 1
            else:
                r = m - 1
        
        return ans