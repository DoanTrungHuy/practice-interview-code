class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        pref = [0 for _ in range(n + 1)]
        
        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]
            
        if pref[n] < target:
            return 0
        
        res = inf
        i = n
        
        while i >= 0 and pref[i] >= target:
            j = bisect_right(pref, pref[i] - target)
            res = min(res, i - j + 1)
            i -= 1
            
        return res