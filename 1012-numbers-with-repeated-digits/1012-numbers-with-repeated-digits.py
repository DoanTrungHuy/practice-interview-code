class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        nums = list(map(int, str(n)))
        sz = len(nums)
        
        @cache
        def dp(i, tight, mask):
            if i == sz:
                return mask != 0
            
            ans = 0
            
            maxi = nums[i] if tight else 9
            
            for d in range(maxi  + 1):
                if mask & (1 << d):
                    continue
                    
                newMask = mask if mask == 0 and d == 0 else (mask | (1 << d))
                
                if tight:
                    ans += dp(i + 1, nums[i] == d, newMask)
                else:
                    ans += dp(i + 1, False, newMask)
                    
            return ans
            
        return n - dp(0, True, 0)