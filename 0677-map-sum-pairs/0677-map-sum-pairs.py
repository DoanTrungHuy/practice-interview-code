class Node:
    def __init__(self):
        self.val = 0
        self.children = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, word: str, val: int) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
        root.val = val
        
    def find(self, prefix: str) -> int:
        root = self.root
        for char in prefix:
            if char not in root.children:
                return 0
            root = root.children[char]
            
        self.res = 0
            
        def dfs(root: Optional[Node]) -> None:
            self.res += root.val
            for suffixNode in root.children.values():
                dfs(suffixNode)
        
        dfs(root)
        
        return self.res
    
class MapSum:

    def __init__(self):
        self.trie = Trie()

    def insert(self, key: str, val: int) -> None:
        self.trie.insert(key, val)

    def sum(self, prefix: str) -> int:
        return self.trie.find(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)