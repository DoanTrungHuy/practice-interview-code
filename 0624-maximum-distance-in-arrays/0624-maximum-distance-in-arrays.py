class Solution:
    def maxDistance(self, a: List[List[int]]) -> int:
        n = len(a)
        
        prev_max = []
        prev_min = []
        suff_max = []
        suff_min = []
        
        for i in range(n):
            if i == 0:
                prev_max.append(a[i][-1])
                prev_min.append(a[i][-0])
            else:
                prev_max.append(max(prev_max[-1], a[i][-1]))
                prev_min.append(min(prev_min[-1], a[i][-0]))
                
        for i in range(n - 1, -1, -1):
            if i == n - 1:
                suff_max.append(a[i][-1])
                suff_min.append(a[i][-0])
            else:
                suff_max.append(max(suff_max[-1], a[i][-1]))
                suff_min.append(min(suff_min[-1], a[i][-0]))
                
        suff_min = suff_min[::-1]
        suff_max = suff_max[::-1]
        
        ans = 0
        
        for i in range(n):
            if i - 1 >= 0:
                ans = max(ans, prev_max[i - 1] - a[i][-0])
                ans = max(ans, a[i][-1] - prev_min[i - 1])
                
            if i + 1 < n:
                ans = max(ans, suff_max[i + 1] - a[i][-0])
                ans = max(ans, a[i][-1] - suff_min[i + 1])
                
        return ans