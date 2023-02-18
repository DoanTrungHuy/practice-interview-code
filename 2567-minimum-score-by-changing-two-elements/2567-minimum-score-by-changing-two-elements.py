class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        nums.sort()
        return min(abs(nums[0] - nums[-3]), abs(nums[1] - nums[-2]), abs(nums[2] - nums[-1]))