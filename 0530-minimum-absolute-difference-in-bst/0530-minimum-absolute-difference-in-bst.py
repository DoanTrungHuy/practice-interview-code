# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.res = inf
        self.pre = -inf
        def dfs(root):
            if root.left:
                dfs(root.left)
            
            self.res = min(self.res, root.val - self.pre)
            self.pre = root.val
            
            if root.right:
                dfs(root.right)
                
        dfs(root)
        
        return self.res