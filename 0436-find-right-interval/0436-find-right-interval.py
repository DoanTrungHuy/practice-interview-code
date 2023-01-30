class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        s = sorted([(interval[0], i) for i, interval in enumerate(intervals)])
        n = len(intervals)
        s.append((10**9, -1))
        
        ans = []
        
        for j in range(n):
            start, end = intervals[j]
            i = bisect_left(s, (end, -1))
            
            # [1, 2], [2, 3], [3, 4]
            #    2       1       0
            
            ans.append(s[i][1])
            
        return ans