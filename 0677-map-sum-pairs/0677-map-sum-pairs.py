class Node:
    def __init__(self):
        self.total = 0
        self.children = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, word: str, diff: int) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
            root.total += diff
        
    def find(self, prefix: str) -> int:
        root = self.root
        for char in prefix:
            if char not in root.children:
                return 0
            root = root.children[char]
        
        return root.total
    
class MapSum:

    def __init__(self):
        self.trie = Trie()
        self.umap = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        diff = val - self.umap[key]
        self.trie.insert(key, diff)
        self.umap[key] = val

    def sum(self, prefix: str) -> int:
        return self.trie.find(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)