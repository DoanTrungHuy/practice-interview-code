from sortedcontainers import SortedList

class MyCalendar:

    def __init__(self):
        self.treeMap = SortedList()

    def book(self, start: int, end: int) -> bool:
        if not self.treeMap:
            self.treeMap.add((end, start))
            return True
            
        i = self.treeMap.bisect_right((start, start))
        
        if i == len(self.treeMap) and self.treeMap[-1][0] <= start:
            self.treeMap.add((end, start))
            return True
        
        if end <= self.treeMap[i][1]:
            self.treeMap.add((end, start))
            return True
        
        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)