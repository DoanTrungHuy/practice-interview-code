class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        memo = {}
        
        @lru_cache(None)
        def dp(i, k):
            if i == n or k == 0:
                return 0
            
            res = dp(i + 1, k)        
            currPiles = 0
    
            for j in range(min(k, len(piles[i]))):
                currPiles += piles[i][j]
                res = max(res, currPiles + dp(i + 1, k - j - 1))
            
            return res
        
        return dp(0, k)