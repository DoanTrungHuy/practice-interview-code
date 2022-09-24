# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.cnt = 0
    
    def countSumNode(self, root, targetSum):
        if not root:
            return
        if root.val == targetSum:
            self.cnt += 1
        self.countSumNode(root.left, targetSum - root.val)
        self.countSumNode(root.right, targetSum - root.val)
    
    def inOrder(self, root, targetSum):
        if not root:
            return
        self.countSumNode(root, targetSum)
        self.inOrder(root.left, targetSum)
        self.inOrder(root.right, targetSum)
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0
        self.inOrder(root, targetSum)
        return self.cnt