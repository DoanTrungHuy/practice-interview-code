class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        words = list(set(words))
        sortWords = sorted(words, key = lambda val: (-cnt[val], val))
        return sortWords[:k]