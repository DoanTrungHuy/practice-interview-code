# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.hm = defaultdict(int)
        
    def dfs(self, root: Optional[TreeNode], res: List[Optional[TreeNode]]) -> str:
        if not root:
            return ''
        s = str(root.val) + ',' + self.dfs(root.left, res) + ',' + self.dfs(root.right, res)
        if self.hm[s] == 1:
            res.append(root)
        self.hm[s] += 1
        return s
        
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        res = []
        self.dfs(root, res)
        return res