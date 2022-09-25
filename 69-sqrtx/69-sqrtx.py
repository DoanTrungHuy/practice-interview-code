class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 0, x
        ans = 0
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if mid * mid <= x:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
                
        return ans