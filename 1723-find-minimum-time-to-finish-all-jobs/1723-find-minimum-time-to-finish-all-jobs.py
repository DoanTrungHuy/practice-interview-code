class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        n = len(jobs)
        flags = [0] * k
        self.minDiff = inf
        
        def backTracking(i):
            if i == n:
                self.minDiff = min(self.minDiff, max(flags))
                return
            
            seen = set()
            
            for j in range(k):
                if flags[j] in seen:
                    continue
                if flags[j] + jobs[i] >= self.minDiff:
                    continue
                    
                seen.add(flags[j])
                flags[j] += jobs[i]
                backTracking(i + 1)
                flags[j] -= jobs[i]
        
        backTracking(0)
        return self.minDiff