class Node:
    def __init__(self, key, val, cnt):
        self.key = key
        self.val = val
        self.cnt = cnt

class LFUCache:
    def __init__(self, capacity: int):
        self.countOfLL = defaultdict(deque)
        self.keyOfNode = defaultdict(Node)
        self.capacity = capacity
        self.minFreq = 0

    def get(self, key: int) -> int:
        if key not in self.keyOfNode:
            return -1

        node = self.keyOfNode[key]
        self.countOfLL[node.cnt].remove(key)

        node.cnt += 1
        self.countOfLL[node.cnt].appendleft(key)

        if not self.countOfLL[self.minFreq]:
            self.minFreq += 1

        return node.val
        

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        
        if key in self.keyOfNode:
            self.keyOfNode[key].val = value
            self.get(key)
        else:
            if len(self.keyOfNode) == self.capacity:
                del self.keyOfNode[self.countOfLL[self.minFreq].pop()]
            self.minFreq = 1
            self.keyOfNode[key] = Node(key, value, self.minFreq)
            self.countOfLL[self.minFreq].appendleft(key)


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)