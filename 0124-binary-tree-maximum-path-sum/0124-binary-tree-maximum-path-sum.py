# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxValue = -inf
        
        def dfs(root):
            if not root:
                return 0
            l = dfs(root.left)
            r = dfs(root.right)
            currValue = root.val + l + r
            self.maxValue = max(self.maxValue, currValue)
            return max(root.val + max(l, r), 0)
        
        dfs(root)
        return self.maxValue