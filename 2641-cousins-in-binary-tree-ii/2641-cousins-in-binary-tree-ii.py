# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        dq = deque([root])
        hm = defaultdict(int)
        cnt = 0
        
        while dq:
            n = len(dq)
            
            for _ in range(n):
                node = dq.popleft()
                hm[cnt] += node.val
                
                if node.left:
                    dq.append(node.left)
                
                if node.right:
                    dq.append(node.right)
                    
            cnt += 1
        
        dq = deque([root])
        cnt = 1
        ans = TreeNode(0)
        dq2 = deque([ans])
        
        while dq:
            n = len(dq)
            
            for _ in range(n):
                node = dq.popleft()
                checkNode = dq2.popleft()
                s = 0
                
                has_left = False
                has_right = False
                
                if node.left:
                    dq.append(node.left)
                    s += node.left.val
                    has_left = True
                
                if node.right:
                    dq.append(node.right)
                    s += node.right.val
                    has_right = True
                    
                if has_left and has_right:
                    checkNode.left = TreeNode(hm[cnt] - s)
                    checkNode.right = TreeNode(hm[cnt] - s)
                    dq2.append(checkNode.left)
                    dq2.append(checkNode.right)
                elif has_left:
                    checkNode.left = TreeNode(hm[cnt] - s)
                    dq2.append(checkNode.left)
                elif has_right:
                    checkNode.right = TreeNode(hm[cnt] - s)
                    dq2.append(checkNode.right)
                
            cnt += 1
        
        return ans