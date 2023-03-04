class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:        
        ans = []
        ranges.sort()
        
        for u, v in ranges:
            if len(ans) == 0 or ans[-1][1] < u:
                ans.append([u, v])
            else:
                ans[-1][1] = max(ans[-1][1], v)
                
        return 2**len(ans) % (10**9 + 7)