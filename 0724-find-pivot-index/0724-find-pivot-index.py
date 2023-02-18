class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        leftSum, total = 0, sum(nums)
        n = len(nums)
        
        for i in range(n):
            if leftSum == total - leftSum - nums[i]:
                return i
            leftSum += nums[i]
        
        return -1