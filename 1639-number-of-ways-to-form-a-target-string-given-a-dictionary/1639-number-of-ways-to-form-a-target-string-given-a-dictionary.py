class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10 ** 9 + 7
        m, n = len(words[0]), len(target)
        charAtIndexCnt = [[0] * m for _ in range(128)]
        for word in words:
            for i, c in enumerate(word):
                charAtIndexCnt[ord(c)][i] += 1

        @lru_cache(None)
        def dp(k, i):
            if i == n:
                return 1
            if k == m:
                return 0
            c = target[i]
            ans = dp(k + 1, i)
            if charAtIndexCnt[ord(c)][k] > 0:
                ans += dp(k + 1, i + 1) * charAtIndexCnt[ord(c)][k]
                ans %= MOD
            return ans

        return dp(0, 0)