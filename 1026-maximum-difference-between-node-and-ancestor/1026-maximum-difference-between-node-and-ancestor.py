# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:  
    def dfs(self, root, maxA, minC):
        if not root:
            return maxA - minC
        maxA = max(maxA, root.val)
        minC = min(minC, root.val)
        return max(self.dfs(root.left, maxA, minC), self.dfs(root.right, maxA, minC))
        
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, -1, inf)
        
        