class Solution:
    def maxScore(self, nums: List[int]) -> int:
        @lru_cache(None)
        def gcd(x, y):
            return math.gcd(x, y)
        
        m = len(nums)
        n = m // 2
        memo = defaultdict(int)
        
        def dp(op, mask):
            if op > n:
                return 0
            
            if mask in memo:
                return memo[mask]
            
            for i in range(m):
                if mask & (1 << i):
                    continue
                for j in range(i + 1, m):
                    if mask & (1 << j):
                        continue
                    newMask = mask | (1 << i) | (1 << j)
                    score = op * gcd(nums[i], nums[j]) + dp(op + 1, newMask)
                    memo[mask] = max(memo[mask], score)
                    
            return memo[mask]
            
        return dp(1, 0)