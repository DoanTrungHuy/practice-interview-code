class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        
        if m*k > n:
            return -1
        
        left, right = min(bloomDay), max(bloomDay)
        ans = -1
        
        while left <= right:
            mid = (left + right) // 2
            
            flower, bouquet = 0, 0
            
            for day in bloomDay:
                if day <= mid:
                    flower += 1
                else:
                    flower = 0
                if flower == k:
                    bouquet += 1
                    flower = 0
                    
            if bouquet >= m:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
                
        return ans