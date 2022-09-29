"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None
        
        dq = deque([root])
        
        while dq:
            n = len(dq)
            rightNode = None
            
            for _ in range(n):
                node = dq.popleft()
                
                node.next = rightNode
                rightNode = node
                    
                if node.left:
                    dq.append(node.right)
                    dq.append(node.left)
                    
        return root