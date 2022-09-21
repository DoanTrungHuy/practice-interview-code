class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        col = int(s[1])
        endCol = int(s[4])
        row = ord(s[0])
        endRow = ord(s[3])
        ans = []
        
        for r in range(row, endRow + 1):
            for c in range(col, endCol + 1):
                ans.append(chr(r) + str(c))
                
        return ans