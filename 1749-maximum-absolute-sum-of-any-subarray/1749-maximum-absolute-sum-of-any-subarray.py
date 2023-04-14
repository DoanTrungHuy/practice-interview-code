class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        maxSub, minSub = nums[0], nums[0]
        maxRes, minRes = nums[0], nums[0]
        n = len(nums)
        
        for i in range(1, n):
            maxSub = max(maxSub + nums[i], nums[i])
            maxRes = max(maxRes, maxSub)
            minSub = min(minSub + nums[i], nums[i])
            minRes = min(minRes, minSub)
            
        return max(maxRes, abs(minRes))