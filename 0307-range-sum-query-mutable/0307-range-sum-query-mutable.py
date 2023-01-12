class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0] * 4 * self.n
        for idx, val in enumerate(nums):
            self.update(1, 1, self.n, idx + 1, val)
        
    def update(self, node, left, right, index, val):
        if not left <= index <= right:
            return
        if left == right:
            self.tree[node] = val
            return
        mid = (left + right) >> 1
        self.update(node * 2, left, mid, index, val)
        self.update(node * 2 + 1, mid + 1, right, index, val)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]
        
    def sumRange(self, node, left, right, qleft, qright):
        if qleft > right or left > qright:
            return 0
        if qleft <= left and right <= qright:
            return self.tree[node]
        mid = (left + right) >> 1
        sumLeft = self.sumRange(node * 2, left, mid, qleft, qright)
        sumRight = self.sumRange(node * 2 + 1, mid + 1, right, qleft, qright)
        return sumLeft + sumRight

class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.it = SegmentTree(nums)

    def update(self, index: int, val: int) -> None:
        self.it.update(1, 1, self.n, index + 1, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.it.sumRange(1, 1, self.n, left + 1, right + 1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)