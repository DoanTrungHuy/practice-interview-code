class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        return min(abs(nums[0] - nums[n - 3]), abs(nums[1] - nums[n - 2]), abs(nums[2] - nums[n - 1]))