# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.ans = []
        
    def dfs(self, root, targetSum, path):
        if not root:
            return
        if not root.left and not root.right and root.val == targetSum:
            self.ans.append(path + [root.val])
            return
        
        self.dfs(root.left, targetSum - root.val, path + [root.val])
        self.dfs(root.right, targetSum - root.val, path + [root.val])
        
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        self.dfs(root, targetSum, [])
        return self.ans