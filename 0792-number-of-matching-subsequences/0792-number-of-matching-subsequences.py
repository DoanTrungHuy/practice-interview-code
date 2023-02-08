class Node:
    def __init__(self, word):
        self.word = word
        self.index = 0

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        buckets = defaultdict(list)
        
        for word in words:
            buckets[word[0]].append(Node(word))
            
        ans = 0
            
        for c in s:
            currBuckets = buckets[c]
            buckets[c] = []
            for node in currBuckets:
                node.index += 1
                if node.index == len(node.word):
                    ans += 1
                else:
                    buckets[node.word[node.index]].append(node)
                    
        return ans