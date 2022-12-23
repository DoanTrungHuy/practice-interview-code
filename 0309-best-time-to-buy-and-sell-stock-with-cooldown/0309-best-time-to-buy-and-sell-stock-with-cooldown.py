class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = {}
        n = len(prices)
        
        def dfs(i, isBuy):
            if i >= n:
                return 0
            
            if (i, isBuy) in dp:
                return dp[(i, isBuy)]
            
            if isBuy:
                buy = dfs(i + 1, not isBuy) - prices[i]
                cooldown = dfs(i + 1, isBuy)
                dp[(i, isBuy)] = max(buy, cooldown)
            else:
                sell = dfs(i + 2, not isBuy) + prices[i]
                cooldown = dfs(i + 1, isBuy)
                dp[(i, isBuy)] = max(sell, cooldown)
                
            return dp[(i, isBuy)]
        
        return dfs(0, True)