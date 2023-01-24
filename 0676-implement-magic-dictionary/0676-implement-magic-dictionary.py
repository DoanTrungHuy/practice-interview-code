class Node:
    def __init__(self):
        self.isLastWord = False
        self.children = defaultdict(Node)
        
class Trie:
    def __init__(self):
        self.root = Node()
        
    def insert(self, word: str) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
        root.isLastWord = True
    
    def find(self, word: str) -> bool:
        root = self.root
        for char in word:
            if char not in root.children:
                return False
            root = root.children[char]
        return root.isLastWord

class MagicDictionary:

    def __init__(self):
        self.trie = Trie()

    def buildDict(self, dictionary: List[str]) -> None:
        for word in dictionary:
            self.trie.insert(word)

    def search(self, searchWord: List[str]) -> bool:
        n = len(searchWord)
        searchWord = list(searchWord)
        
        for i in range(n):
            for step in range(26):
                if step == ord(searchWord[i]) - ord('a'):
                    continue
                tmp = searchWord[i]
                searchWord[i] = chr(step + ord('a'))
                if self.trie.find(searchWord):
                    return True
                searchWord[i] = tmp
                
        return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dictionary)
# param_2 = obj.search(searchWord)