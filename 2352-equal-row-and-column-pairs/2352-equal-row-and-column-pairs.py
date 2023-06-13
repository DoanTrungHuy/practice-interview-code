class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        mapping = defaultdict(int)
        
        for arr in grid:
            mapping[tuple(arr)] += 1
            
        cnt = 0
        
        for arr in zip(*grid):
            cnt += mapping[tuple(arr)]
            
        return cnt