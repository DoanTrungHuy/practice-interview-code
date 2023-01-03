class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total = sum(matchsticks)
        
        if total % 4 != 0:
            return False
        
        n = len(matchsticks)
        k = 4
        d = total // k
        flags = [0] * k
        self.check = False
        
        def backTracking(i):
            if self.check:
                return
            
            if i == n:
                if flags[0] == flags[1] and flags[1] == flags[2] and flags[2] == flags[3]:
                    self.check = True
                return
            
            seen = set()
            
            for j in range(k):
                if flags[j] in seen:
                    continue
                if flags[j] + matchsticks[i] > d:
                    continue
                seen.add(flags[j])
                flags[j] += matchsticks[i]
                backTracking(i + 1)
                flags[j] -= matchsticks[i]
                
        backTracking(0)
                
        return self.check