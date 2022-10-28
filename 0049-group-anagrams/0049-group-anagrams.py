class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        words = defaultdict(list)
        n = len(strs)
        
        for i in range(n):
            words[tuple(sorted(strs[i]))].append(strs[i])
            
        return list(words.values())