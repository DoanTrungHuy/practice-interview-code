class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        n = len(words)
        s = set()
        
        for i in range(n - 1):
            dummy = words[i][::-1]
            for j in range(i + 1, n):
                if dummy == words[j]:
                    s.add(words[j])
                    s.add(words[i])
                    break
        
        return len(s) // 2