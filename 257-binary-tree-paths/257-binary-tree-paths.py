# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, path):
        if not root.left and not root.right:
            self.ans.append(path)
            return
        
        if root.left:
            self.dfs(root.left, path + '->' + str(root.left.val))
        if root.right:
            self.dfs(root.right, path + '->' + str(root.right.val))
        
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.ans = []
        if not root:
            return self.ans
        self.dfs(root, str(root.val))
        return self.ans