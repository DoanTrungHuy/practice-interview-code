class Node:
    def __init__(self, val):
        self.val = val
        self.children = {}
        self.suggestions = []
        
class Trie:
    def __init__(self):
        self.root = Node(None)
        
    def insert(self, word: str) -> None:
        root = self.root
        for char in word:
            if char not in root.children:
                root.children[char] = Node(char)
            if len(root.suggestions) < 3:
                root.suggestions.append(word)
            root = root.children[char]
        
        if len(root.suggestions) < 3:
            root.suggestions.append(word)
            
    def find(self, searchWord: str) -> List[List[str]]:
        root = self.root
        ans = []
        for char in searchWord:
            if char in root.children:
                root = root.children[char]
                ans.append(root.suggestions)
            else:
                break
        remaining = len(searchWord) - len(ans)
        for _ in range(remaining):
            ans.append([])
        return ans

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        trie = Trie()
        for word in products:
            trie.insert(word)
        return trie.find(searchWord)
        