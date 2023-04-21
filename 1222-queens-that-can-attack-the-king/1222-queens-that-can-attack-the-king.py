class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        checkQueens = set((x, y) for x, y in queens)
        x = king[0]
        y = king[1]
        res = []
        
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                for spill in range(1, 8):
                    nx = x + dx*spill
                    ny = y + dy*spill
                    
                    if (nx, ny) in checkQueens:
                        res.append([nx, ny])
                        break
                        
        return res