class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        n = len(nums)
        ans = nums[n - 1]
        
        for i in range(n - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                nums[i] = nums[i] + nums[i + 1]
            ans = max(ans, nums[i])
            
        return ans