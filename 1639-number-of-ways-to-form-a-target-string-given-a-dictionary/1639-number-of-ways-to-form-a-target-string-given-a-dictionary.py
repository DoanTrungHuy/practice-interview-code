class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10**9 + 7
        m, n = len(words[0]), len(target)
        
        freq = [Counter() for _ in range(m)]
        
        for word in words:
            for i, char in enumerate(word):
                freq[i][char] += 1
        
        @lru_cache(None)
        def dp(i, j):
            if j == n:
                return 1
            if i == m:
                return 0
            return (dp(i + 1, j) + dp(i + 1, j + 1) * freq[i][target[j]]) % MOD
        
        return dp(0, 0)