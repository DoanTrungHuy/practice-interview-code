class LUPrefix:
    def __init__(self, n: int):
        self.check = [False] * (n + 2)
        self.check[0] = True
        self.maxIdx = 1

    def upload(self, video: int) -> None:
        self.check[video] = True
        while self.check[self.maxIdx]:
            self.maxIdx += 1

    def longest(self) -> int:
        return self.maxIdx - 1

# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()