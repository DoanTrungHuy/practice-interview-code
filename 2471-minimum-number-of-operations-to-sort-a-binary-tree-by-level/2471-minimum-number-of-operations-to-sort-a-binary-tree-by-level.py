# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def minSwaps(t):
            n = len(t)
            arrpos = [*enumerate(t)]
            arrpos.sort(key = lambda it : it[1])
            vis = {k : False for k in range(n)}

            ans = 0
            for i in range(n):
                if vis[i] or arrpos[i][0] == i:
                    continue
                sz = 0
                j = i
                while not vis[j]:
                    vis[j] = True
                    j = arrpos[j][0]
                    sz += 1

                if sz > 0:
                    ans += (sz - 1)
            return ans
        
        dq = deque([root])
        cnt = 0
        while dq:
            n = len(dq)
            t = []
            for _ in range(n):
                node = dq.popleft()
                t += [node.val]
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            cnt += minSwaps(t)
            
        return cnt
            
            