class TrieNode:
    def __init__(self):
        self.isEndWord = False
        self.children = defaultdict(TrieNode)
        
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        root = self.root
        for char in word:
            root = root.children[char]
        root.isEndWord = True
        
    def find(self, word: str) -> None:
        root = self.root
        for char in word:
            if char not in root.children:
                return False
            root = root.children[char]
        return root.isEndWord

    def dfs(self, s: str, path: str, i: int) -> List[str]:
        if i == len(s):
            return [path[:-1]]
        ans = []
        for j in range(i + 1, len(s) + 1):
            sp = s[i:j]
            if self.find(sp):
                ans += self.dfs(s, path + sp + ' ', j)
        return ans
        
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        trie = Trie()
        
        for word in wordDict:
            trie.insert(word)
            
        return trie.dfs(s, '', 0)