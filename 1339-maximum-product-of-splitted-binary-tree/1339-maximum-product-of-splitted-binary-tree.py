# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.ans = 0
        self.total = 0
        
    def dfs(self, root):
        if not root:
            return 0
        currSum = self.dfs(root.left) + self.dfs(root.right) + root.val
        self.ans = max(self.ans, currSum * (self.total - currSum))
        return currSum
        
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.total = self.dfs(root)
        self.dfs(root)
        return self.ans % (10**9 + 7)