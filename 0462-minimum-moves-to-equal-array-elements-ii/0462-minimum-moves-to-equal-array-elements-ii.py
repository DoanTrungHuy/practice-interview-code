class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        med = sorted(nums)[len(nums) // 2]
        return sum([abs(num - med) for num in nums])