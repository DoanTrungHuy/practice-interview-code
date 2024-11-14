class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def f(x):
            cnt = 0
            
            for q in quantities:
                cnt += ceil(q / x)
                
            return cnt <= n
        
        l = 1
        r = 10**9
        a = -1
        
        while l <= r:
            m = (l + r) >> 1
            
            if f(m):
                a = m
                r = m - 1
            else:
                l = m + 1
                
        return a