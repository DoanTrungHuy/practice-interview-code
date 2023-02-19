class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        DIR = [-1, 0, 1, 0, -1]
        n = len(board)
        m = len(board[0])
        
        def dfs(x, y):
            if not (0 <= x and x < n and 0 <= y and y < m and board[x][y] != '.'):
                return
            board[x][y] = '.'
            for i in range(4):
                dfs(x + DIR[i], y + DIR[i + 1])
                
        cnt = 0
        
        for i in range(n):
            for j in range(m):
                if board[i][j] == '.':
                    continue
                cnt += 1
                dfs(i, j)
                
        return cnt