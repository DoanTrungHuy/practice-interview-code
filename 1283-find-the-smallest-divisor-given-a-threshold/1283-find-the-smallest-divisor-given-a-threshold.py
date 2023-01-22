class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l, r = 1, sum(nums)
        ans = inf
        
        while l <= r:
            m = (l + r) // 2
            
            if sum([ceil(num / m) for num in nums]) <= threshold:
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
                
        return ans