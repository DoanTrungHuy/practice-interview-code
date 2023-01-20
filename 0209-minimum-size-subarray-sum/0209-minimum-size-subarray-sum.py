class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, 0
        res = inf
        total = 0
        
        while r < n:
            total += nums[r]
            r += 1
            while total >= target:
                res = min(res, r - l)
                total -= nums[l]
                l += 1
        
        return 0 if res == inf else res