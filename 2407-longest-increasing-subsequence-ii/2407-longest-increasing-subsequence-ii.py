class SegmentTree:
    def __init__(self, n):
        self.tree = [0 for _ in range(4*n)]
        
    def update(self, node, left, right, index, value):
        if left > index or index > right:
            return
        if left == right:
            self.tree[node] = value
            return
        mid = (left + right) // 2
        self.update(2*node, left, mid,  index, value)
        self.update(2*node + 1, mid + 1, right, index, value)
        self.tree[node] = max(self.tree[2*node], self.tree[2*node + 1])
        
    def get(self, node, left, right, qleft, qright):
        if qleft > right or qright < left:
            return -inf
        if qleft <= left and right <= qright:
            return self.tree[node]
        mid = (left + right) // 2
        leftMax = self.get(node*2, left, mid, qleft, qright)
        rightMax = self.get(node*2 + 1, mid + 1, right, qleft, qright)
        return max(leftMax, rightMax)
    
class Solution:
    def lengthOfLIS(self, nums: List[int], k: int) -> int:
        maxEle = max(nums)
        it = SegmentTree(maxEle)
        ans = 1
        
        for num in nums:
            preMax = it.get(1, 0, maxEle, max(0, num - k), num - 1)
            ans = max(ans, preMax + 1)
            it.update(1, 0, maxEle, num, preMax + 1)
            
        return ans