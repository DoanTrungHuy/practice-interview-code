class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def trimDays(target: int) -> int:
            day = 1
            total = 0
            
            for weight in weights:
                if total + weight <= target:
                    total += weight
                else:
                    total = weight
                    day += 1
            
            return day
        
        l, r = max(weights), sum(weights)
        ans = inf
        
        while l <= r:
            m = (l + r) // 2
            
            if trimDays(m) <= days:
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
                
        return ans