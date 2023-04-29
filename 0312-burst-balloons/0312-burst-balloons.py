class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        memo = {}
        
        def dp(i, j):
            if i >= j:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]
            ans = 0
            for k in range(i + 1, j):
                ans = max(ans, nums[i] * nums[k] * nums[j] + dp(i, k) + dp(k, j))
            memo[(i, j)] = ans
            return ans
        
        return dp(0, n - 1)