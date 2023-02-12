class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        l = 0
        n = len(nums)
        r = n - 1
        ans = 0
        
        while l < r:
            ans += int(str(nums[l]) + str(nums[r]))
            l += 1
            r -= 1
            
        if n & 1:
            ans += nums[l]
            
        return ans