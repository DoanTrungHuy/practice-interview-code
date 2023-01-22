class Solution:
    def minCost(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [inf for _ in range(n + 2)]
        dp[0] = 0
        
        for i in range(n):
            cnt = [0 for _ in range(n)]
            trimmed = 0
            for j in range(i + 1, n + 1):
                cnt[nums[j - 1]] += 1
                if cnt[nums[j - 1]] == 2:
                    trimmed += 2
                elif cnt[nums[j - 1]] > 2:
                    trimmed += 1
                dp[j] = min(dp[j], dp[i] + k + trimmed)
            
        return dp[n]