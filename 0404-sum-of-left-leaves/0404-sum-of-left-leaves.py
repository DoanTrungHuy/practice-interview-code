# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        
        def dfs(root, isLeft = False):
            if not root:
                return
            
            if isLeft and not root.left and not root.right:
                self.ans += root.val
                
            dfs(root.left, True)
            dfs(root.right, False)
                
        dfs(root)
        
        return self.ans