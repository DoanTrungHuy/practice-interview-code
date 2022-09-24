# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, parenVal):
        if not root:
            return 0
        longestLeft = self.dfs(root.left, root.val)
        longestRight = self.dfs(root.right, root.val)
        self.longest = max(self.longest, longestLeft + longestRight)
        return max(longestLeft, longestRight) + 1 if parenVal == root.val else 0
    
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        self.longest = 0
        self.dfs(root, None)
        return self.longest