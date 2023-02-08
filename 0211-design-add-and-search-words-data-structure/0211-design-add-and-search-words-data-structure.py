class TrieNode:
    def __init__(self):
        self.isEndWord = False
        self.children = defaultdict(TrieNode)       

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        root = self.root
        
        for char in word:
            root = root.children[char]
            
        root.isEndWord = True

    def search(self, word: str) -> bool:
        def dfs(word, root):
            if not word:
                return root.isEndWord
            
            if word[0] != '.':
                if word[0] not in root.children:
                    return False
                if dfs(word[1:], root.children[word[0]]):
                    return True
            else:
                for node in root.children.values():
                    if dfs(word[1:], node):
                        return True
                    
            return False
        
        return dfs(word, self.root)
            


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)