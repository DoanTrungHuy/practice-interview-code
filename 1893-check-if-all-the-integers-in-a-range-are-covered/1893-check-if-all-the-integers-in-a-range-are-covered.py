class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        MAX_RANGE = 50
        line = [0] * (MAX_RANGE + 2)
        
        for r in ranges:
            x = r[0]
            y = r[1]
            line[x] += 1
            line[y + 1] -= 1
            
        for i in range(1, MAX_RANGE + 2):
            line[i] += line[i - 1]
            if left <= i <= right and line[i] <= 0:
                return False
            
        return True