class TrieNode:
    def __init__(self):
        self.isWord = False
        self.children = {}
        self.cnt = defaultdict(int)

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.cnt[char] += 1
            
        node.isWord = True

    def search(self, word: str) -> int:
        node = self.root
        cnt = 0
        
        for char in word:
            node = node.children[char]
            cnt += node.cnt[char] 
        
        return cnt


class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        for word in words:
            trie.insert(word)
            
        ans = []
        
        for word in words:
            ans.append(trie.search(word))
            
        return ans
        