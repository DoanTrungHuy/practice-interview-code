# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        dq = deque([root])
        level = 0
        ans = []
        
        while dq:
            n = len(dq)
            tmp = [0 for _ in range(n)]
            
            for i in range(n):
                node = dq.popleft()
                
                if level:
                    tmp[n - i - 1] = node.val
                else:
                    tmp[i] = node.val
                    
                if node.left:
                    dq.append(node.left)
                    
                if node.right:
                    dq.append(node.right)
                    
            level = not level
            ans.append(tmp)
            
        return ans