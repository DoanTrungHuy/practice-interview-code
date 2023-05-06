# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root):
        if not root:
            return 0
        longestLeft = self.dfs(root.left)
        longestRight = self.dfs(root.right)
        self.longest = max(self.longest, longestLeft + longestRight)
        return max(longestLeft, longestRight) + 1
        
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.longest = 0
        self.dfs(root)
        return self.longest