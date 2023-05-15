# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        dq = deque([root])
        ans = []
        
        while dq:
            n = len(dq)
            s, c = 0, 0
            
            for _ in range(n):
                node = dq.popleft()
                s += node.val
                c += 1
                
                if node.left:
                    dq.append(node.left)
                    
                if node.right:
                    dq.append(node.right)
                    
            ans.append(s / c)
            
        return ans