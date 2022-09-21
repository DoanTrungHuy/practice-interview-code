class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ans = []
        
        for i in range(n - 2):
            tmp = []
            for j in range(m - 2):
                maxEle = -float('inf')
                for x in range(i, i + 3):
                    for y in range(j, j + 3):
                        maxEle = max(maxEle, grid[x][y])
                tmp.append(maxEle)
            ans.append(tmp)
            
        return ans