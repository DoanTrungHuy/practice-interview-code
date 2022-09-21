# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, original, cloned, target):
        if original is None:
            return
        if target == original:

            self.ans = cloned
            return
        
        self.dfs(original.left, cloned.left, target)
        self.dfs(original.right, cloned.right, target)
        
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self.ans = None
        self.dfs(original, cloned, target)
        
        return self.ans