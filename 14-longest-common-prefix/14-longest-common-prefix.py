class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        
        revCols = list(zip(*strs))
        
        ans = ''
        
        for row in revCols:
            if len(set(row)) == 1:
                ans += row[0]
            else:
                break
        
        return ans