import numpy as np

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        nums = np.zeros((n, n), dtype = np.int16)
        
        for x1, y1, x2, y2 in queries:
            nums[x1:x2 + 1, y1:y2 + 1] += 1
            
        return nums