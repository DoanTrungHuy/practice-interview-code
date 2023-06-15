# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        idxMax = 1
        valMax = -float('inf')
        dq = deque([root])
        step = 1
        
        while dq:
            n = len(dq)
            s = 0
            
            for _ in range(n):
                node = dq.popleft()
                s += node.val
                
                if node.left:
                    dq.append(node.left)
                    
                if node.right:
                    dq.append(node.right)
            
            if s > valMax:
                valMax = s
                idxMax = step
            
            step += 1
            
        return idxMax