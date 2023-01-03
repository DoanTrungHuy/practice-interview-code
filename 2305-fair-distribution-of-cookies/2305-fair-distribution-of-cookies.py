class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n = len(cookies)
        self.flags = [0] * k
        self.minDiff = inf
        
        def backTracking(i):
            if i == n:
                self.minDiff = min(self.minDiff, max(self.flags))
                return
            
            seen = set()
            
            for j in range(k):
                if self.flags[j] + cookies[i] >= self.minDiff:
                    continue
                if self.flags[j] in seen:
                    continue
                    
                seen.add(self.flags[j])
                self.flags[j] += cookies[i]
                backTracking(i + 1)
                self.flags[j] -= cookies[i]
        
        backTracking(0)
        return self.minDiff