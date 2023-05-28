from sortedcontainers import SortedList

class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        n = len(chargeTimes)
        j = 0
        ans = 0
        total = 0
        sl = SortedList()
        
        for i in range(n):
            total += runningCosts[i]
            sl.add(chargeTimes[i])
            while sl and sl[-1] + (i - j + 1) * total > budget:
                total -= runningCosts[j]
                sl.remove(chargeTimes[j])
                j += 1
                
            ans = max(ans, i - j + 1)
            
        return ans