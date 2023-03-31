class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l, r = 0, n - 1
        mod = 10**9 + 7
        
        nums.sort()
        
        p = [1]
        
        for i in range(n):
            p.append((2 * p[-1]) % mod)
            
        ans = 0
        
        while l <= r:
            if nums[l] + nums[r] <= target:
                ans = (ans + p[r - l]) % mod
                l += 1
            else:
                r -= 1
                
        return ans