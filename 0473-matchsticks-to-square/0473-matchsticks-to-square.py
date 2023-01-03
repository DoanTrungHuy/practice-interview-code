class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total = sum(matchsticks)
        
        if total % 4 != 0:
            return False
        
        n = len(matchsticks)
        k = 4
        self.d = total // k
        flags = [0] * k
        self.check = False
        matchsticks.sort(reverse = True)
        
        def backTracking(i):
            if self.check:
                return
            
            if i == n:
                self.check = True
                return
            
            seen = set()
            
            for j in range(k):
                if flags[j] in seen:
                    continue
                if flags[j] + matchsticks[i] > self.d:
                    continue
                seen.add(flags[j])
                flags[j] += matchsticks[i]
                backTracking(i + 1)
                flags[j] -= matchsticks[i]
                
        backTracking(0)
                
        return self.check