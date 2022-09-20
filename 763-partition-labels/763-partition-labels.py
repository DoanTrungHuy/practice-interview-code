class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        prev = -1
        save = defaultdict(int)
        n = len(s)
        
        for i in range(n):
            save[s[i]] = i
            
        maxIndex = 0
        ans = []
        
        for i in range(n):
            maxIndex = max(maxIndex, save[s[i]])
            
            if maxIndex == i:
                ans.append(i - prev)
                prev = i
                
        return ans