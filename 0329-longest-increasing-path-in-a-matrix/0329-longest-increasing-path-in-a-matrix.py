class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        r, c = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(c)] for _ in range(r)]
        DIR = [-1, 0, 1, 0, -1]
        def dfs(x, y):
            if dp[x][y] != 0:
                return dp[x][y]
            ans = 1
            for i in range(4):
                nx = x + DIR[i]
                ny = y + DIR[i + 1]
                if 0 <= nx < r and 0 <= ny < c:
                    if matrix[x][y] < matrix[nx][ny]:
                        ans = max(ans, 1 + dfs(nx, ny))
            dp[x][y] = ans
            return ans
        ans = 0
        for x in range(r):
            for y in range(c):
                ans = max(ans, dfs(x, y))
        return ans