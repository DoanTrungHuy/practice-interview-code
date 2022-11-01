class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        # [
        #     [ 1, 1, 1,-1,-1],
        #     [ 1, 1, 1,-1,-1],
        #     [-1,-1,-1, 1, 1],
        #     [ 1, 1, 1, 1,-1],
        #     [-1,-1,-1,-1,-1]
        # ]
        
        r, c = len(grid), len(grid[0])
        ans = []
        
        for i in range(c):
            currCol = i
            for j in range(r):
                nextCol = currCol + grid[j][currCol]
                
                if nextCol < 0 or nextCol >= c or grid[j][currCol] != grid[j][nextCol]:
                    currCol = -1
                    break
                    
                currCol = nextCol
            ans.append(currCol)
            
        return ans