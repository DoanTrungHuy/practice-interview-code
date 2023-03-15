class Solution:
    def maxArea(self, h: int, w: int, ho: List[int], ve: List[int]) -> int:
        ho.sort()
        ve.sort()
        maxH = max(ho[0], h - ho[-1])
        maxV = max(ve[0], w - ve[-1])
        
        mod, n, m = pow(10, 9) + 7, len(ho), len(ve)
        
        for i in range(n - 1):
            maxH = max(maxH, ho[i + 1] - ho[i])
        
        for i in range(m - 1):
            maxV = max(maxV, ve[i + 1] - ve[i])
            
        return (maxH * maxV) % mod