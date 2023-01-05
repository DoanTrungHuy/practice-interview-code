class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: x[1])
        prev, cnt = -inf, 0
        
        for start, end in intervals:
            if start >= prev:
                prev = end
            else:
                cnt += 1
                
        return cnt
        
        # [1, 2], [1, 3], [2, 3], [3, 4]