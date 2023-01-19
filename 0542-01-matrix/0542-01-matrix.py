class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        r, c = len(mat), len(mat[0])
        
        dq = deque([])
        
        for i in range(r):
            for j in range(c):
                if mat[i][j] == 0:
                    dq.append((i, j))
                else:
                    mat[i][j] = -1
        
        DIR = [-1, 0, 1, 0, -1]
        
        while dq:
            n = len(dq)
            x, y = dq.popleft()
            
            for i in range(4):
                xx = x + DIR[i]
                yy = y + DIR[i + 1]
                
                if 0 <= xx < r and 0 <= yy < c and mat[xx][yy] == -1:
                    dq.append((xx, yy))
                    mat[xx][yy] = mat[x][y] + 1
                    
        return mat
                