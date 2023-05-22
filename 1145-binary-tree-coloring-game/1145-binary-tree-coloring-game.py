# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        leftX, rightX = 0, 0
        
        def dfs(root):
            nonlocal leftX, rightX
            if not root:
                return 0
            l = dfs(root.left)
            r = dfs(root.right)
            if root.val == x:
                leftX, rightX = l, r
            return r + l + 1
        
        dfs(root)
        
        cntX = leftX + rightX + 1
        
        if cntX < n / 2:
            return True
        
        if leftX > n / 2 or rightX > n / 2:
            return True
        
        return False