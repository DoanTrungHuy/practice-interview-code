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
        
        for r1, r2, r3 in combinations(top3, 3):
            for a, b, c in product(r1, r2, r3):
                if a[1] != b[1] and a[1] != c[1] and b[1] != c[1]:
                    max_sum = max(max_sum, a[0] + b[0] + c[0])
                                    
        return max_sum