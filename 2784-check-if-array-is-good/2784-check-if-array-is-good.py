class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums)
        c = list(range(1, n)) + [n - 1]
        return sorted(nums) == c