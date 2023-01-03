class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        nums = list(map(int, str(n)))
        sz = len(nums)
        
        @cache
        def dp(i, tight, rep, mask):
            if i == sz:
                return 1 if rep else 0
            
            ans = 0
            
            maxi = nums[i] if tight else 9
            
            for d in range(maxi + 1):    
                newTight = tight and nums[i] == d
                newMask = mask if mask == 0 and d == 0 else (mask | (1 << d))
                newRep = rep or (mask & (1 << d))
                ans += dp(i + 1, newTight, newRep, newMask)
                    
            return ans
            
        return dp(0, True, False, 0)