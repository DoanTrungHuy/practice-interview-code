# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        dq = deque([root])
        cnt = 0
        
        while dq:
            n = len(dq)
            
            for _ in range(n):
                node = dq.popleft()
                
                if node.left:
                    dq.append(node.left)
                    
                if node.right:
                    dq.append(node.right)
                    
            cnt += 1
            
        return cnt