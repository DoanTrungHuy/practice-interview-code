class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        ans = [''] * numRows 
        idx, step = 0, 1
        
        for c in s:
            ans[idx] += c
            if idx == 0:
                step = 1
            elif idx == numRows - 1:
                step = -1
            idx += step
            
        return ''.join(ans)