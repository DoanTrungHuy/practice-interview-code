# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 1, n
        ans = n
        
        while l <= r:
            m = l + (r - l) // 2
            
            if isBadVersion(m):
                ans = m
                r = m - 1
            else:
                l = m + 1
                
        return ans