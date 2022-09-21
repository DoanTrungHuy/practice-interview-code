# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        dq = deque([root])
        s = 0
        
        while dq:
            n = len(dq)
            s = 0
            for i in range(n):
                node = dq.popleft()
                s += node.val
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
                    
        return s