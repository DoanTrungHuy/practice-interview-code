class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        # d = 2
        # jobDifficulty: abcd
        # max(a) + max(b, c, d) | max(a, b) + max(c, d) | max(a, b, c) + d 
        
        n = len(jobDifficulty)
        
        if n < d:
            return -1
        
        @lru_cache(None)
        
        def dfs(i, d):
            if d == 1:
                return max(jobDifficulty[i:])
            
            maxDay = 0
            minJob = inf
            
            for j in range(i, n - d + 1):
                maxDay = max(maxDay, jobDifficulty[j])
                minJob = min(minJob, maxDay + dfs(j + 1, d - 1))
                
            return minJob
        
        return dfs(0, d)