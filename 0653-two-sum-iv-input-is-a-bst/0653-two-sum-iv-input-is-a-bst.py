# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.check = False
        self.hashSet = set()
        
    def LNR(self, root, k):
        if not root or self.check:
            return
        self.LNR(root.left, k)
        if root.val in self.hashSet:
            self.check = True
        self.hashSet.add(k - root.val)
        self.LNR(root.right, k)
        
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.LNR(root, k)
        return self.check
