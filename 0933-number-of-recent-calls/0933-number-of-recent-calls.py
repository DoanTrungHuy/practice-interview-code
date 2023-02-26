class RecentCounter:

    def __init__(self):
        self.dq = deque()

    def ping(self, t: int) -> int:
        self.dq.append(t)
        
        while self.dq[0] < self.dq[-1] - 3000:
            self.dq.popleft()
            
        return len(self.dq)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)