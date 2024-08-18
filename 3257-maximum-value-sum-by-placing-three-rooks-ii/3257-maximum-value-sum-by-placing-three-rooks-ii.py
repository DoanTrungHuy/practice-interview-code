class Solution:
    def maximumValueSum(self, board: List[List[int]]) -> int:
        m,n = len(board), len(board[0])
        data = []
        
        for r in board:
            h = []
            for i,v in enumerate(r):
                if len(h) == 3: 
                    heappushpop(h, (v,i))
                else: 
                    heappush(h, (v,i))
            data.append(h)
        
        h = []
        for i,r in enumerate(data):
            for v,j in r:
                if len(h) == 12: 
                    heappushpop(h, (v, i, j))
                else: 
                    heappush(h, (v,i,j))
                    
        res = -math.inf
        
        for x,y,z in combinations(h, 3):
            sa, sb = {x[1], y[1], z[1]}, {x[2], y[2], z[2]}
            if len(sa) == 3 and len(sb) == 3:
                res = max(res, x[0] + y[0] + z[0])
                
        return res