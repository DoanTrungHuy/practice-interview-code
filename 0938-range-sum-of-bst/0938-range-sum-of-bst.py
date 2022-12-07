# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.total = 0
        
    def dfs(self, root, low, high):
        if not root:
            return
        
        if low <= root.val <= high:
            self.total += root.val
            
        self.dfs(root.left, low, high)
        self.dfs(root.right, low, high)
        
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.dfs(root, low, high)
        return self.total