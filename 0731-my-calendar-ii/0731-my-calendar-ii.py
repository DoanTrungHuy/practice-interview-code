from sortedcontainers import SortedList

class MyCalendarTwo:

    def __init__(self):
        self.sl = SortedList()

    def book(self, start: int, end: int) -> bool:
        self.sl.add((start, 1))
        self.sl.add((end, -1))
        
        group = 0
        ans = True
        
        for element in self.sl:
            group += element[1]
            if group == 3:
                ans = False
                break
        
        if not ans:
            self.sl.discard((start, 1))
            self.sl.discard((end, -1))
            
        return ans


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)