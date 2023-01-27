class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        waters = [jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity]
        limit = jug1Capacity + jug2Capacity
        dq = deque([0])
        visited = set([0])
        
        while dq:
            capacity = dq.popleft()
            
            if capacity == targetCapacity:
                return True
            
            for water in waters:
                newCapacity = capacity + water
                if 0 <= newCapacity <= limit and newCapacity not in visited:
                    dq.append(newCapacity)
                    visited.add(newCapacity)
                    
        return False