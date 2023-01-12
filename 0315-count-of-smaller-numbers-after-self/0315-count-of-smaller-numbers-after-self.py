class SegmentTree:
    def __init__(self, maxVal):
        self.tree = [0] * 4 * maxVal
        
    def update(self, node, left, right, index):
        if not left <= index <= right:
            return
        if left == right:
            self.tree[node] += 1
            return
        mid = (left + right) >> 1
        self.update(node * 2, left, mid, index)
        self.update(node * 2 + 1, mid + 1, right, index)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]
        
    def sumRange(self, node, left, right, qleft, qright):
        if right < qleft or qright < left:
            return 0
        if qleft <= left and right <= qright:
            return self.tree[node]
        mid = (left + right) >> 1
        sumLeft = self.sumRange(node * 2, left, mid, qleft, qright)
        sumRight = self.sumRange(node * 2 + 1, mid + 1, right, qleft, qright)
        return sumLeft + sumRight
    
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        for i in range(n):
            nums[i] += 10**4 + 1
            
        maxVal = max(nums)
        res = [0 for _ in range(n)]
        it = SegmentTree(maxVal)
        
        for i in range(n - 1, -1, -1):
            res[i] = it.sumRange(1, 1, maxVal, 1, nums[i] - 1)
            it.update(1, 1, maxVal, nums[i])
        
        return res