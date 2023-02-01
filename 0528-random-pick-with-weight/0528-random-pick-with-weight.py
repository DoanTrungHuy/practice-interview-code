class Solution:

    def __init__(self, w: List[int]):
        t = sum(w)
        w = list(map(lambda x: x/t, w))
        n = len(w)
        for i in range(1, n):
            w[i] += w[i - 1]
        self.w = w

    def pickIndex(self) -> int:
        rd = random.random()
        return bisect_left(self.w, rd)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()