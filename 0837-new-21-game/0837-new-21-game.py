class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0:
            return 1.0
        
        window_sum = 0
        
        for sum_ in range(k, k + maxPts):
            window_sum += int(sum_ <= n)
            
        dp = {}
        
        for i in range(k - 1, -1, -1):
            dp[i] = window_sum / maxPts
            remove = 0
            if i + maxPts <= n:
                remove = dp.get(i + maxPts, 1)
            window_sum += dp[i] - remove
        
        return dp[0]