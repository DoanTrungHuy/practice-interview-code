class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        ans, prev = 0, 0
        n = len(nums)
        
        for num in nums:
            ans += max(prev - num, 0)
            prev = max(prev, num) + 1
        
        return ans