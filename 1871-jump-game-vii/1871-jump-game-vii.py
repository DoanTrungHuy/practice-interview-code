class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] == '1':
            return False
        
        n = len(s)
        
        dq = deque([0])
        currMax = 0
        
        while dq:
            i = dq.popleft()
            
            for j in range(max(i + minJump, currMax + 1), min(i + maxJump + 1, n)):
                if s[j] == '0':
                    if j == n - 1:
                        return True
                    dq.append(j)
                    
            currMax = max(i + maxJump, currMax)
                    
        return False