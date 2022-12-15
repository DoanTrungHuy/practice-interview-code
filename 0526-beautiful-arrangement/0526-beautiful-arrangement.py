class Solution:
    def __init__(self):
        self.cnt = 0
        self.flag = []
        
    def backTracking(self, n, i):
        if i > n:
            self.cnt += 1
            return
        
        for j in range(1, n + 1):
            if self.flag[j] == 0 and (i % j == 0 or j % i == 0):
                self.flag[j] = True
                self.backTracking(n, i + 1)
                self.flag[j] = False
        
    def countArrangement(self, n: int) -> int:
        self.flag = [False] * (n + 1)
        self.backTracking(n, 1)
        return self.cnt