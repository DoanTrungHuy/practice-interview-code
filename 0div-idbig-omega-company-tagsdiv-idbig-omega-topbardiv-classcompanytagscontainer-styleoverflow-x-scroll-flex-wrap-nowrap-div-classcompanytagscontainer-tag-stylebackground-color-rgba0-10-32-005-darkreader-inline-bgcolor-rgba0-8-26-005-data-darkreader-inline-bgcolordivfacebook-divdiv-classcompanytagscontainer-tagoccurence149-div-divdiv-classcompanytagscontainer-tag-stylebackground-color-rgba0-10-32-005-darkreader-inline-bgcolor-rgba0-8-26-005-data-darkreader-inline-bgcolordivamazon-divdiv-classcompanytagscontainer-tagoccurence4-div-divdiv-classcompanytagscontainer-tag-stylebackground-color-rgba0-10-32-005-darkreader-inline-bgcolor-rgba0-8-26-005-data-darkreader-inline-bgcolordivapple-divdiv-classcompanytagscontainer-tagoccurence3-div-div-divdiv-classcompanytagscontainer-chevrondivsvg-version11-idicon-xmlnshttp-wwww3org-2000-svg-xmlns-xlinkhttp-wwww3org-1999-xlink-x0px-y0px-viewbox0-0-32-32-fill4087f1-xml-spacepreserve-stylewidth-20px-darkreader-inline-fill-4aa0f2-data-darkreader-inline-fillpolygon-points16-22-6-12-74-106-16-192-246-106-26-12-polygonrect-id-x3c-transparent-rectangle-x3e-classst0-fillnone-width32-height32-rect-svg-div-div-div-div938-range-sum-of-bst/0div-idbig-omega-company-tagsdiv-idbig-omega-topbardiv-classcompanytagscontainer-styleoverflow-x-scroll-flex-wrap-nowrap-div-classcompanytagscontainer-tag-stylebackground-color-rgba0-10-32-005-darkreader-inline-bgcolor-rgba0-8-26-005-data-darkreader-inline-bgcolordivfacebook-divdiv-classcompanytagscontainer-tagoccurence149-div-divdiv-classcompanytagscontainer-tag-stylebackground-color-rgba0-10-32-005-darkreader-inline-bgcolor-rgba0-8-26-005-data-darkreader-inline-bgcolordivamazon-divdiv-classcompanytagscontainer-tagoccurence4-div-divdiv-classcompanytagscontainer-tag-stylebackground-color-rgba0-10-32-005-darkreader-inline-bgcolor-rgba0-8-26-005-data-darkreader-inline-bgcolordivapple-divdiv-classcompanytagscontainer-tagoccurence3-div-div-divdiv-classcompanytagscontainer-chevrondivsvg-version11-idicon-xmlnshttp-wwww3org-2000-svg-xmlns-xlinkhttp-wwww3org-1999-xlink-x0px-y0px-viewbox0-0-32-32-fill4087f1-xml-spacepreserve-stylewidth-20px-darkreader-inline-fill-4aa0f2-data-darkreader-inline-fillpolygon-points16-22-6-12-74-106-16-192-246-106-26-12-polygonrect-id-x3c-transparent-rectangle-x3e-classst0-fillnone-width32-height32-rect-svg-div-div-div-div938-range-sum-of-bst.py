# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def dfs(root):
            if not root:
                return 0
            s = 0
            if low <= root.val <= high:
                s += root.val
            s += dfs(root.left)
            s += dfs(root.right)
            return s
            
        return dfs(root)