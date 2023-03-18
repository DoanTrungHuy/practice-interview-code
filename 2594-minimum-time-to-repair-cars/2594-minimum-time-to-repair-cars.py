class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        ranks.sort()
        
        left, right = 1, pow(10, 14)
        ans = 0
        
        while left <= right:
            mid = (left + right) // 2
            totalCars = 0
            for rank in ranks:
                cntCars = int(sqrt(mid // rank))
                totalCars += cntCars
                
            if totalCars >= cars:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return ans