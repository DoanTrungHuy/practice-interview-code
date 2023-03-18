class ListNode:
    def __init__(self, url, prevNode = None, nextNode = None):
        self.url = url
        self.prevNode = prevNode
        self.nextNode = nextNode

class BrowserHistory:

    def __init__(self, homepage: str):
        self.curr = ListNode(homepage)

    def visit(self, url: str) -> None:
        self.curr.nextNode = ListNode(url, self.curr)
        self.curr = self.curr.nextNode

    def back(self, steps: int) -> str:
        for _ in range(steps):
            if self.curr.prevNode:
                self.curr = self.curr.prevNode
            else:
                break
        return self.curr.url

    def forward(self, steps: int) -> str:
        for _ in range(steps):
            if self.curr.nextNode:
                self.curr = self.curr.nextNode
            else:
                break
        return self.curr.url


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)