# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        
        dq = deque([root])
        
        ans = []
        
        while dq:
            n = len(dq)
            m = -float('inf')
            
            for _ in range(n):
                node = dq.popleft()
                m = max(m, node.val)
                
                if node.left:
                    dq.append(node.left)
                    
                if node.right:
                    dq.append(node.right)
                    
            ans.append(m)
            
        return ans