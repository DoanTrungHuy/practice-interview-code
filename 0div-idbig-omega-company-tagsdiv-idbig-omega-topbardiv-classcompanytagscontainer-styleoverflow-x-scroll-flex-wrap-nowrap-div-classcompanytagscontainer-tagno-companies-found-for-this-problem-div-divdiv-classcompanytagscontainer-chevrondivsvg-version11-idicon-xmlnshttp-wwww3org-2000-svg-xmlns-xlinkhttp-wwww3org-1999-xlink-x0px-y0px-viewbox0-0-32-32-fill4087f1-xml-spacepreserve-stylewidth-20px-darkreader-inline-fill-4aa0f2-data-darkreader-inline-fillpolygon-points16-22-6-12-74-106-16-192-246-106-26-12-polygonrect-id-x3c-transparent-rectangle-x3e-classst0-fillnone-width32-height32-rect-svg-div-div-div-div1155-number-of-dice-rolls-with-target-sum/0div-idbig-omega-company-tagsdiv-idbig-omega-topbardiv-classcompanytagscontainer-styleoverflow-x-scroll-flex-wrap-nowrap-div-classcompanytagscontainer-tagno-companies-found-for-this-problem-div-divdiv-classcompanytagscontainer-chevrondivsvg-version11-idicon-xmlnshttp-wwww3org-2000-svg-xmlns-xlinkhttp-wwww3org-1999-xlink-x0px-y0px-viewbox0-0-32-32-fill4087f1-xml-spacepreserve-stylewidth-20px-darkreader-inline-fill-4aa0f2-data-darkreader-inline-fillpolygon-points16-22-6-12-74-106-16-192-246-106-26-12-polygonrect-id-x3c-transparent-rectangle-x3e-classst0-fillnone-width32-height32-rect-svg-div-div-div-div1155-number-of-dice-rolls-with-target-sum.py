class Solution:
    def __init__(self):
        self.dp = {}
        
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        if n == 0 or target <= 0:
            return n == target
        
        if (n, target) in self.dp:
            return self.dp[(n, target)]
        
        ans = 0
        MOD = 10**9 + 7
        
        for i in range(1, k + 1):
            ans = (ans + self.numRollsToTarget(n - 1, k, target - i)) % MOD
        
        self.dp[(n, target)] = ans
        
        return ans