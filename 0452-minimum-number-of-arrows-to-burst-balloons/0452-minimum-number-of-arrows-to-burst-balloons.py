class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: x[1])
        prev, cnt = -inf, 0
        
        for start, end in points:
            if start > prev:
                prev = end
            else:
                cnt += 1
                
        return len(points) - cnt