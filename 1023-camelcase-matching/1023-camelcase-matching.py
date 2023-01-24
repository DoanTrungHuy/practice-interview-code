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
        
    def isMatches(self, word: str) -> bool:
        root = self.root
        
        for char in word:
            if char not in root.children and char.isupper():
                return False
            elif char in root.children:
                root = root.children[char]
                
        return root.isEndWord

class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        trie = Trie()
        trie.insert(pattern)
        return [trie.isMatches(word) for word in queries]