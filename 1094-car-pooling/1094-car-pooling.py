from sortedcontainers import SortedList

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        line = SortedList()
        
        for numPassengers, from_, to_ in trips:
            line.add((from_, numPassengers))
            line.add((to_, -numPassengers))
            
        group = 0
        
        for _, member in line:
            group += member
            
            if group > capacity:
                return False
        
        return True