from math import gcd

class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        n = len(nums)
        c = 0
        
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                c += g == k
                
        return c