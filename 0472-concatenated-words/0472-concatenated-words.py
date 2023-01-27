class Node:
    def __init__(self):
        self.char = ''
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
        
    def find(self, word: str) -> int:
        root = self.root
        
        for char in word:
            if char not in root.children:
                return False
            root = root.children[char]
            
        return root.isEndWord
        

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        trie = Trie()
        
        for word in words:
            trie.insert(word)
        
        @cache
        def dfs(i, n, word, cnt):
            root = trie.root
            for j in range(i, n):
                if word[j] not in root.children:
                    return False
                root = root.children[word[j]]
                if root.isEndWord:
                    if j == n - 1: 
                        return cnt >= 1
                    elif dfs(j + 1, n, word, cnt + 1):
                        return True
            return False
        
        ans = []
        
        for word in words:
            if dfs(0, len(word), word, 0):
                ans.append(word)
                
        return ans