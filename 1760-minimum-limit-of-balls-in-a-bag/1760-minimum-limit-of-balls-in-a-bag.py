class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l, r = 1, max(nums)
        ans = inf
        
        while l <= r:
            m = (l + r) // 2
            
            if sum([ceil(num / m) - 1 for num in nums]) <= maxOperations:
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
                
        return ans