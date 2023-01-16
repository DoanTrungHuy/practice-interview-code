class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        ans = [[0 for _ in range(n)] for _ in range(n)]
        
        for x1, y1, x2, y2 in queries:
            for r in range(x1, x2 + 1):
                ans[r][y1] += 1
                if y2 + 1 < n:
                    ans[r][y2 + 1] -= 1
                    
        for r in range(n):
            for c in range(1, n):
                ans[r][c] += ans[r][c - 1]
                
        return ans