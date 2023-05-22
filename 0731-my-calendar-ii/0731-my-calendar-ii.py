from sortedcontainers import SortedList

class MyCalendarTwo:

    def __init__(self):
        self.line = SortedList()

    def book(self, start: int, end: int) -> bool:
        self.line.add((start, 1))
        self.line.add((end, -1))
        
        group = 0
        ans = True
        
        for element in self.line:
            group += element[1]
            if group == 3:
                ans = False
                break
        
        if not ans:
            self.line.discard((start, 1))
            self.line.discard((end, -1))
            
        return ans


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)