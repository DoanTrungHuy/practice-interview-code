class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)
        
        for i in range(n):
            row = set()
            for j in range(n):
                if board[i][j] in row:
                    return False
                if '0' <= board[i][j] <= '9':
                    row.add(board[i][j]) 
                
        for j in range(n):
            col = set()
            for i in range(n):
                if board[i][j] in col:
                    return False
                if '0' <= board[i][j] <= '9':
                    col.add(board[i][j])  
        
        for i in range(0, n - 2, 3):
            for j in range(0, n - 2, 3):
                mat = set()
                for x in range(i, i + 3):
                    for y in range(j, j + 3):
                        if board[x][y] in mat:
                            return False
                        if '0' <= board[x][y] <= '9':
                            mat.add(board[x][y]) 
        
        return True