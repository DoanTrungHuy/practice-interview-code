class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        ans = inf
        
        while l <= r:
            m = (l + r) // 2
            if sum([ceil(pile / m) for pile in piles]) <= h:
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
                
        return ans