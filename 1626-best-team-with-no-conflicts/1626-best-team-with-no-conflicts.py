class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(scores)
        dp = [0] * n 
        
        players = sorted(zip(ages, scores))
        ans = 0
        
        for i in range(n):
            dp[i] = players[i][1]
            for j in range(i):
                if players[j][1] <= players[i][1]:
                    dp[i] = max(dp[i], dp[j] + players[i][1])
            ans = max(ans, dp[i])
            
        return ans