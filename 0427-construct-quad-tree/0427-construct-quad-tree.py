"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def dfs(x, y, size):
            if size == 1:
                return Node(grid[x][y], 1, None, None, None, None)
            
            isDuplicate = True
            
            for i in range(x, x + size):
                for j in range(y, y + size):
                    if grid[i][j] != grid[x][y]:
                        isDuplicate = False
                        break
                if not isDuplicate:
                    break
            
            if not isDuplicate:
                half = size // 2
                topLeft = dfs(x, y, half)
                topRight = dfs(x, y + half, half)
                bottomLeft = dfs(x + half, y, half)
                bottomRight = dfs(x + half, y + half, half)
                return Node(grid[x][y], 0, topLeft, topRight, bottomLeft, bottomRight)
            
            return Node(grid[x][y], 1, None, None, None, None)
        
        return dfs(0, 0, len(grid))
            