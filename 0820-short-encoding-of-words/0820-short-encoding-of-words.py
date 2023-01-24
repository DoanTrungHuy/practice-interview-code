class Node:
    def __init__(self):
        self.children = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word: str) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
    
    def isNotPrefix(self, word: str) -> bool:
        root = self.root
        for char in word:
            root = root.children[char]
        return len(root.children) == 0

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        answ = 0
        trie = Trie()
        
        words = list(set(words))
        
        for word in words:
            trie.insert(word[::-1])
            
        for word in words:
            answ += len(word) + 1 if trie.isNotPrefix(word[::-1]) else 0
            
        return answ