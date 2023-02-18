class ListNode:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap:

    def __init__(self):
        self.constMaxN = 19997
        self.contains = [None for _ in range(self.constMaxN)]
        
    def hashing(self, key: int) -> int:
        return key % self.constMaxN

    def put(self, key: int, value: int) -> None:
        self.remove(key)
        h = self.hashing(key)
        
        if self.contains[h] == None:
            self.contains[h] = ListNode(key, value)
        else:
            head = self.contains[h]
            newNode = ListNode(key, value)
            newNode.next = head
            self.contains[h] = newNode

    def get(self, key: int) -> int:
        h = self.hashing(key)
        currNode = self.contains[h]
        while currNode:
            if currNode.key == key:
                return currNode.value
            currNode = currNode.next
        return -1

    def remove(self, key: int) -> None:
        h = self.hashing(key)
        head = self.contains[h]
        
        if head == None:
            return
        if head.key == key:
            self.contains[h] = head.next
            return
        currNode = head
        while currNode.next:
            if currNode.next.key == key:
                currNode.next = currNode.next.next
                return
            currNode = currNode.next
            


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)