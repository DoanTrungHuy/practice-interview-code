class Solution:
    def maxRepOpt1(self, text: str) -> int:
        dp = [(c, len(list(cList))) for c, cList in groupby(text)]
        cnt = defaultdict(int)
        res = 0
        
        for v, c in dp:
            cnt[v] += 1
            res = max(res, c)
        
        dp = [('$', 0)] + dp + [('$', 0)]
        n = len(dp)
        
        for i in range(1, n - 1):
            if cnt[dp[i][0]] > 1:
                res = max(res, dp[i][1] + 1)
                
            if dp[i][1] == 1 and dp[i - 1][0] == dp[i + 1][0]:
                res = max(res, dp[i - 1][1] + dp[i + 1][1] + int(cnt[dp[i - 1][0]] > 2))
                
        return res