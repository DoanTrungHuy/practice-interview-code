# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return []
        
        dq = deque([root])
        check = []
        
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
                    
            check.append(s)
            
        check = sorted(check)
        
        if len(check) < k:
            return -1
            
        return check[-k]