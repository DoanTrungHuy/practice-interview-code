class SummaryRanges:

    def __init__(self):
        self.intervals = []

    def addNum(self, value: int) -> None:
        heappush(self.intervals, [value, value])

    def getIntervals(self) -> List[List[int]]:
        tmp = []
        
        while self.intervals:
            cur = heappop(self.intervals)
            if tmp and cur[0] <= tmp[-1][1] + 1:
                tmp[-1][1] = max(tmp[-1][1], cur[1])
            else:
                tmp.append(cur)
        
        self.intervals = tmp
        
        return self.intervals


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()