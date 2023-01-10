class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        nums = list(map(int, str(n)))
        sizeDigit = len(nums)
        
        @cache
        def dp(i, tight, mask):
            if i == sizeDigit:
                return 1 if mask else 0
            
            limit = nums[i] if tight else 9
            limit += 1
            ans = 0
            
            for d in range(limit):
                if mask & (1 << d):
                    continue
                newTight = tight and d == nums[i]
                newMask = mask if d == 0 and mask == 0 else mask | (1 << d)
                ans += dp(i + 1, newTight, newMask)
                
            return ans
            
        return dp(0, True, 0)