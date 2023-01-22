class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def trimNums(target: int) -> int:
            cnt = 1
            total = 0
            
            for num in nums:
                if total + num <= target:
                    total += num
                else:
                    cnt += 1
                    total = num
                    
            return cnt
        
        l, r, ans = max(nums), sum(nums), inf
        
        while l <= r:
            m = (l + r) >> 1
            if trimNums(m) <= k:
                ans = min(ans, m)
                r = m - 1
            else:
                l = m + 1
                
        return ans