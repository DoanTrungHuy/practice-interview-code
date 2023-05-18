# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == p or root == q:
            return root
        
        nodeLeft, nodeRight = None, None
        
        if root.left:
            nodeLeft = self.lowestCommonAncestor(root.left, p, q)
            
        if root.right:
            nodeRight = self.lowestCommonAncestor(root.right, p, q)
            
        if nodeLeft and nodeRight:
            return root
        
        return nodeLeft or nodeRight