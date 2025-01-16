class Solution:
    def __init__(self):
        self.memo = {}
        self.coins = []
        self.rows = 0
        self.cols = 0

    def dp(self, i, j, k):
        # Base case: reaching the bottom-right cell
        if i == self.rows - 1 and j == self.cols - 1:
            return 0 if k and self.coins[i][j] < 0 else self.coins[i][j]

        # Check memoization
        if (i, j, k) in self.memo:
            return self.memo[(i, j, k)]

        ans = float('-inf')

        # Case when the current cell is negative, and we can ignore it
        if self.coins[i][j] < 0 and k:
            if i + 1 < self.rows:
                ans = max(ans, self.dp(i + 1, j, k - 1))
            if j + 1 < self.cols:
                ans = max(ans, self.dp(i, j + 1, k - 1))

        # Normal case, including the current cell value
        if i + 1 < self.rows:
            ans = max(ans, self.dp(i + 1, j, k) + self.coins[i][j])
        if j + 1 < self.cols:
            ans = max(ans, self.dp(i, j + 1, k) + self.coins[i][j])

        # Memoize and return the result
        self.memo[(i, j, k)] = ans
        return ans

    def maximumAmount(self, coins):
        self.coins = coins
        self.rows = len(coins)
        self.cols = len(coins[0])
        self.memo = {}
        return self.dp(0, 0, 2)
