class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        nums = list(map(int, str(10 ** n - 1)))
        sz = len(nums)
        
        @cache
        def dp(i, tight, mask):
            if i == sz:
                return 1
            
            limit = nums[i] if tight else 9
            limit += 1
            ans = 0
            
            for d in range(limit):
                if mask & (1 << d):
                    continue
                newTight = tight and d == nums[i]
                newMask = mask if mask == 0 and d == 0 else mask | (1 << d)
                
                ans += dp(i + 1, newTight, newMask)
                
            return ans
        
        return dp(0, True, 0)