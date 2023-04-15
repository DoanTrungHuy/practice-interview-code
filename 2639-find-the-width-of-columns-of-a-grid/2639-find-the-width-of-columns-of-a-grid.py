class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        return [max([len(str(r)) for r in row]) for row in zip(*grid)]