class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        subArr = 0
        subMax = 0
        
        hm = {}
        
        for i in range(len(chars)):
            hm[chars[i]] = vals[i]
        
        for c in s:
            if c in chars:
                subArr = max(hm[c], subArr + hm[c])
            else:
                subArr = max(ord(c) - ord('a') + 1, subArr + ord(c) - ord('a') + 1)
            subMax = max(subMax, subArr)
            
        return subMax