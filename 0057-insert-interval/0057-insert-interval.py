class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        l = bisect_left([b for _, b in intervals], newInterval[0])
        r = bisect_right([a for a, _ in intervals], newInterval[1])
        
        if l < len(intervals):
            newInterval[0] = min(newInterval[0], intervals[l][0])
            
        if r > 0:
            newInterval[1] = max(newInterval[1], intervals[r - 1][1])
            
        return intervals[:l] + [newInterval] + intervals[r:]