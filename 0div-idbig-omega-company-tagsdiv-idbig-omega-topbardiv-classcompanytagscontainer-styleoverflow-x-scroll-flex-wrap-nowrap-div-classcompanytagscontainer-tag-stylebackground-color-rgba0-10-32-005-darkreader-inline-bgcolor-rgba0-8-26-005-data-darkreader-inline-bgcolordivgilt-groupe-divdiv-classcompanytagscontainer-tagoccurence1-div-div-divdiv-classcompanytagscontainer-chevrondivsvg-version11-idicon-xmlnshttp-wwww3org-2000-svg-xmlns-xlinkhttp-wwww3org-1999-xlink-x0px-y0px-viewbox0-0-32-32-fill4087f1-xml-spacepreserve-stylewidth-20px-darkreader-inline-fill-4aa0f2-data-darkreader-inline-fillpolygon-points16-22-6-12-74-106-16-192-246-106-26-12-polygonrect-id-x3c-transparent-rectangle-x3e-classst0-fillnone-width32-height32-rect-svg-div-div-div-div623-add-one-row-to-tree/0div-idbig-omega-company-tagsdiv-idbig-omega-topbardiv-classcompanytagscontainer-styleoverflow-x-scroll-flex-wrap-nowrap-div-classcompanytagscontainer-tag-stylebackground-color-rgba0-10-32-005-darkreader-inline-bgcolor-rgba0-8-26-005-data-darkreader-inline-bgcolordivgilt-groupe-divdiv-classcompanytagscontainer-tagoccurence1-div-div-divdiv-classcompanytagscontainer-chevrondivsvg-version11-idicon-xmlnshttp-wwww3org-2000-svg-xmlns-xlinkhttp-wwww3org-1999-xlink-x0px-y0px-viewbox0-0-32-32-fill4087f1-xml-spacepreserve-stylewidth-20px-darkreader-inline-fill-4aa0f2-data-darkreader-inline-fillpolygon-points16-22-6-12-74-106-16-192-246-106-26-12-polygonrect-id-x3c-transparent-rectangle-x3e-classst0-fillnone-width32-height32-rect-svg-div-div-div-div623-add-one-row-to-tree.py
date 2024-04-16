# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            node = TreeNode(val)
            node.left = root
            root = node
            return root
        
        dq = deque([root])
        de = 1
        
        while dq:
            de += 1
            n = len(dq)
            
            if de == depth:
                break
                
            for _ in range(n):
                node = dq.popleft()
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

        while dq:
            node = dq.popleft()
            nodeLeft, nodeRight = node.left, node.right
            node.left = TreeNode(val)
            node.right = TreeNode(val)
            node.left.left = nodeLeft
            node.right.right = nodeRight
            
        return root