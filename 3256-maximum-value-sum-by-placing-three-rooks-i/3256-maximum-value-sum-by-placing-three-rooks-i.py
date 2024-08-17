class Solution:
    def maximumValueSum(self, board: List[List[int]]) -> int:
        m = len(board)
        n = len(board[0])
        
        max_sum = -10**18
        
        top3 = []
        
        for i in range(m):
            tmp = []
            
            for j, v in enumerate(board[i]):
                tmp.append((board[i][j], j))
                
            top3.append(sorted(tmp)[::-1][:3])
        
        for i1 in range(m):
            for i2 in range(i1 + 1, m):
                for i3 in range(i2 + 1, m):
                    for v1, j1 in top3[i1]:
                        for v2, j2 in top3[i2]:
                            for v3, j3 in top3[i3]:
                                if j1 != j2 and j2 != j3 and j3 != j1:
                                    max_sum = max(max_sum, v1 + v2 + v3)
                                    
        return max_sum