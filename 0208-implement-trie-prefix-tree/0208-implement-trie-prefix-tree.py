class Node:
    def __init__(self):
        self.isEndWord = False
        self.children = defaultdict(Node)

class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
        root.isEndWord = True

    def search(self, word: str) -> bool:
        root = self.root
        for char in word:
            if char not in root.children:
                return False
            root = root.children[char]
        return root.isEndWord

    def startsWith(self, prefix: str) -> bool:
        root = self.root
        for char in prefix:
            if char not in root.children:
                return False
            root = root.children[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)