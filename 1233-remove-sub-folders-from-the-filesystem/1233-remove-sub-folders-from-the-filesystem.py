class Node:
    def __init__(self):
        self.children = {}
        self.isEndWord = False

class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word: List[str]) -> None:
        root = self.root
        for char in word:
            if char not in root.children:
                root.children[char] = Node()
            root = root.children[char]
        root.isEndWord = True
        
    def find(self, word: List[str]) -> bool:
        root = self.root
        for char in word:
            if root.isEndWord:
                return True
            if char not in root.children:
                return False
            root = root.children[char]
        return root.isEndWord

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        trie = Trie()
        answ = []
        
        for subFolder in folder:
            trimSlat = subFolder.split('/')[1:]
            if not trie.find(trimSlat):
                trie.insert(trimSlat)
                answ.append(subFolder)
                
        return answ