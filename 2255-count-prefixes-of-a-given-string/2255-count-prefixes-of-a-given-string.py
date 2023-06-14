class Node:
    def __init__(self):
        self.isChar = False
        self.child = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, word):
        root = self.root
        for char in word:
            root = root.child[char]
            root.isChar = True
    
    def find(self, word):
        root = self.root
        for char in word:
            if char not in root.child:
                return False
            root = root.child[char]
        return root.isChar

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        trie = Trie()
        
        trie.insert(s)
        cnt = 0
        
        for word in words:
            cnt += int(trie.find(word))
            
        return cnt