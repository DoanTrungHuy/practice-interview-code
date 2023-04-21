class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        MOD = 10**9 + 7
        memo = {}
        
        def dp(i, p, n):
            if i == len(group):
                return 1 if p >= minProfit else 0
            
            if (i, p, n) in memo:
                return memo[(i, p, n)]
            
            res = dp(i + 1, p, n) % MOD
            if n - group[i] >= 0:
                res = (res + dp(i + 1, min(p + profit[i], 101), n - group[i])) % MOD
                
            memo[(i, p, n)] = res
            return res
        
        return dp(0, 0, n)