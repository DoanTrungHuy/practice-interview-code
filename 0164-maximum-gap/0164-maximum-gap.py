class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        
        for i in range(n - 1):
            ans = max(ans, nums[i + 1] - nums[i])
            
        return ans