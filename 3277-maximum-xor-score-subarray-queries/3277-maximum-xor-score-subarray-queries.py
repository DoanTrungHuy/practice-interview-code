class Solution:
    def maximumSubarrayXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        @lru_cache(None)
        def cal_xor(l, r):
            if l == r:
                return nums[l]
            return cal_xor(l, r - 1) ^ cal_xor(l + 1, r)
        
        @lru_cache(None)
        def dp(l, r):
            if l == r:
                return nums[l]
            return max(cal_xor(l, r), dp(l, r - 1), dp(l + 1, r))
        
        return [dp(l, r) for l, r in queries]