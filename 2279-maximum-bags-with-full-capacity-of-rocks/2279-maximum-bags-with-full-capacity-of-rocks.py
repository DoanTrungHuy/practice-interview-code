class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        bag = []
        n = len(capacity)
        
        for i in range(n):
            bag.append((capacity[i], rocks[i]))
            
        bag.sort(key = lambda x: x[0] - x[1])
        
        cnt = 0
        
        for i in range(n):
            deviant = bag[i][0] - bag[i][1]
            if deviant > 0:
                additionalRocks -= deviant
            if additionalRocks < 0:
                break
            cnt += 1
        
        return cnt