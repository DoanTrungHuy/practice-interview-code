class Solution:
    def findIntegers(self, n: int) -> int:
        nums = []
        
        while n > 0:
            nums.append(n % 2)
            n //= 2
            
        if len(nums) == 0:
            nums.append(0)
        
        nums = nums[::-1]
        
        sz = len(nums)
        
        @cache
        def dp(i, tight, prev):
            if i == sz:
                return 1
            
            limit = nums[i] if tight else 1
            limit += 1
            ans = 0
            
            for d in range(limit):
                if d == 1 and prev == 1:
                    continue
                newTight = tight and d == nums[i]
                ans += dp(i + 1, newTight, d)
            
            return ans
            
        return dp(0, True, 0)