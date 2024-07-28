class TextEditor:

    def __init__(self):
        self.txt = ""
        self.p = 0

    def addText(self, text: str) -> None:
        self.txt = self.txt[:self.p] + text + self.txt[self.p:]
        self.p += len(text)

    def deleteText(self, k: int) -> int:
        n = len(self.txt)
        self.txt = self.txt[:max(0, self.p - k)] + self.txt[self.p:]
        self.p = max(0, self.p - k)
        return n - len(self.txt)

    def cursorLeft(self, k: int) -> str:
        self.p = max(self.p - k, 0)  
        return self.txt[max(0, self.p - 10):self.p]

    def cursorRight(self, k: int) -> str:
        self.p = min(self.p + k, len(self.txt))  
        return self.txt[max(0, self.p - 10):self.p]
        


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)