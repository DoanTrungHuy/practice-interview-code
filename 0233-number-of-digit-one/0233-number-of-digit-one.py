class Solution:
    def countDigitOne(self, n: int) -> int:
        nums = list(map(int, str(n)))
        sz = len(nums)
        
        @cache
        def dp(i, cnt, tight):
            if i == sz:
                return cnt
            
            limit = nums[i] if tight else 9
            ans = 0
            
            for d in range(limit + 1):
                newCnt = cnt + (d == 1)
                newTight = tight and d == nums[i]
                
                ans += dp(i + 1, newCnt, newTight)
                
            return ans
        
        return dp(0, 0, True)