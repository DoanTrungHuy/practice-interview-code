class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        h = []
        n = len(profits)
        p = list(zip(capital, profits))
        i = 0
        
        p.sort()
        
        for _ in range(k):
            while i < n and p[i][0] <= w:
                heappush(h, -p[i][1])
                i += 1
            if not h:
                break
            w -= heappop(h)
            
        return w