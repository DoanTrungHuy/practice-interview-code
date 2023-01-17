from sortedcontainers import SortedList

class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.hashMap = defaultdict(SortedList)
        n = len(arr)
        
        for i in range(n):
            self.hashMap[arr[i]].add(i)

    def query(self, left: int, right: int, value: int) -> int:
        c = self.hashMap[value]
        return c.bisect_right(right) - c.bisect_left(left)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)