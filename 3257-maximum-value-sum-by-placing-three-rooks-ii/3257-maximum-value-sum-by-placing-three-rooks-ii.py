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
            
        new_dataset = []
            
        for i in range(m):
            for v, j in top3[i]:
                if len(new_dataset) == 15:
                    heappop(new_dataset)
                    heappush(new_dataset, (v, i, j))
                else:
                    heappush(new_dataset, (v, i, j))
        
        for d1, d2, d3 in combinations(new_dataset, 3):
            ur, uc = {d1[1], d2[1], d3[1]}, {d1[2], d2[2], d3[2]}
            if len(ur) == 3 and len(uc) == 3:
                max_sum = max(max_sum, d1[0] + d2[0] + d3[0])
                                    
        return max_sum