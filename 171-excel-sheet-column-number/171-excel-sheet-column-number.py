class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        res = 0
        for idx, col in enumerate(columnTitle):
            res = res * 26 + (ord(col) - ord('A')) + 1
        return res