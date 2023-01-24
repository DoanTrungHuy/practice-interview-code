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
        
    def replace(self, word: str) -> str:
        root = self.root
        repWord = ''
        for char in word:
            repWord += char
            if char not in root.children:
                return word
            if root.children[char].isEndWord:
                return repWord
            root = root.children[char]
        return word
        

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        sentence = sentence.split()
        trie = Trie()
        
        for word in dictionary:
            trie.insert(word)
        
        n = len(sentence)
        
        for i in range(n):
            sentence[i] = trie.replace(sentence[i])
            
        return ' '.join(sentence)