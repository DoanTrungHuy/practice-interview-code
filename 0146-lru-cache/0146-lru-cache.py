class LRUCache:

    def __init__(self, capacity: int):
        self.di = dict()
        self.dq = deque()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.di:
            return -1
        self.dq.remove(key)
        self.dq.append(key)
        return self.di[key]

    def put(self, key: int, value: int) -> None:
        if key in self.di:
            self.dq.remove(key)
        else:
            if len(self.dq) == self.capacity:
                del self.di[self.dq.popleft()]
        self.dq.append(key)
        self.di[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)