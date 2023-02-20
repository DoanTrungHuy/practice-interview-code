class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        heaters.sort()
        houses.sort()
        n = len(houses)
        m = len(heaters)
        ans, j = 0, 0
        
        for i in range(n):
            while j < m - 1 and abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i]):
                j += 1
            ans = max(ans, abs(heaters[j] - houses[i]))
            
        return ans