class UndergroundSystem:

    def __init__(self):
        self.checkInMap = {}
        self.totalRoute = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkInMap[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, time = self.checkInMap[id]
        endStation = stationName
        route = (startStation, endStation)
        if route not in self.totalRoute:
            self.totalRoute[route] = [0, 0]
            
        self.totalRoute[route][0] += t - time
        self.totalRoute[route][1] += 1
    
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        route = (startStation, endStation)
        total, cnt = self.totalRoute[route]
        return total / cnt


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)