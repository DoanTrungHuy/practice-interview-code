class MinStack:

    def __init__(self):
        self.stackNormal = []
        self.stackMinVal = []

    def push(self, val: int) -> None:
        self.stackNormal.append(val)
        if len(self.stackMinVal) == 0 or val <= self.stackMinVal[-1]:
            self.stackMinVal.append(val)

    def pop(self) -> None:
        if self.stackMinVal[-1] == self.stackNormal[-1]:
            self.stackMinVal.pop()
        self.stackNormal.pop()

    def top(self) -> int:
        return self.stackNormal[-1]

    def getMin(self) -> int:
        return self.stackMinVal[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()