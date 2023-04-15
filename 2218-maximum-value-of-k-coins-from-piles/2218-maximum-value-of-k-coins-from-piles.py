class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        
        @lru_cache(None)
        def dp(i, coins):
            if i == n or coins == 0:
                return 0
            
            res = dp(i + 1, coins)        
            currPiles = 0
    
            for j in range(min(coins, len(piles[i]))):
                currPiles += piles[i][j]
                res = max(res, currPiles + dp(i + 1, coins - j - 1))
                
            return res
        
        return dp(0, k)