# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        MAXN = int(10**6)
        self.mi_node = [0]*MAXN
        self.ma_node = [0]*MAXN
        
        def dfs(root):
            if not root:
                return
            
            self.mi_node[root.val] = root.val
            self.ma_node[root.val] = root.val
            
            
            dfs(root.left)
            dfs(root.right)
            
            self.mi_node[root.val] = min(
                self.mi_node[root.val], 
                self.mi_node[root.left.val] if root.left else root.val,
                self.mi_node[root.right.val] if root.right else root.val
            )
                
            self.ma_node[root.val] = max(
                self.ma_node[root.val], 
                self.ma_node[root.left.val] if root.left else root.val,
                self.ma_node[root.right.val] if root.right else root.val
            )
            
        dfs(root)
        
        self.ans = 0
        
        def dfs2(root):
            if not root:
                return
            
            self.ans = max(self.ans, abs(root.val - self.mi_node[root.val]))
            self.ans = max(self.ans, abs(root.val - self.ma_node[root.val]))
            
            dfs2(root.left)
            dfs2(root.right)
            
        dfs2(root)
        
        return self.ans