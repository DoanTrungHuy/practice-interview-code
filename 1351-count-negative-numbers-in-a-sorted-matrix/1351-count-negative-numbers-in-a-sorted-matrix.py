class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        cnt = 0
        
        for i in range(n):
            if grid[i][m - 1] > 0:
                continue
            
            if grid[i][0] < 0:
                cnt += m
                continue
                
            l, r = 0, m - 1
            p = m
            
            while l <= r:
                mid = l + (r - l) // 2
                
                if grid[i][mid] < 0:
                    r = mid - 1
                else:
                    l = mid + 1
    
            cnt += m - l
            
        return cnt