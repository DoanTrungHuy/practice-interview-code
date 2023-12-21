class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        pointxs = sorted([x for x, y in points])
        prev = pointxs[0]
        res = 0
        
        for p in pointxs:
            res = max(res, p - prev)
            prev = p
            
        return res