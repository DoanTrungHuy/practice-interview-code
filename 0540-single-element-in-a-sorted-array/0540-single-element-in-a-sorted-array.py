class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n == 1:
            return nums[0]
        if nums[n - 1] != nums[n - 2]:
            return nums[n - 1]
        
        l = 0
        r = n - 1
        ans = 0
        
        while l <= r:
            m = (l + r) >> 1
            if nums[m] == nums[m^1]:
                l = m + 1
            else:
                ans = nums[m]
                r = m - 1
        
        return ans