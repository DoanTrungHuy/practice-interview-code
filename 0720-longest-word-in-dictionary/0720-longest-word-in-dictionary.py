class TrieNode:
    def __init__(self):
        self.isEndWord = False
        self.word = ''
        self.children = defaultdict(TrieNode)
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        self.root.isEndWord = True
        
    def insert(self, word):
        root = self.root
        
        for char in word:
            root = root.children[char]
            
        root.isEndWord = True
        root.word = word
        
    def find(self):
        res = ''
        dq = deque([self.root])
        
        while dq:
            n = len(dq)
            
            for _ in range(n):
                root = dq.popleft()
                
                if not root.isEndWord:
                    continue
                
                if len(res) < len(root.word) or root.word < res:
                    res = root.word
                
                for child in root.children.values():
                    dq.append(child)
                    
        return res
                

class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        
        for word in words:
            trie.insert(word)
            
        return trie.find()