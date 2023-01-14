class Solution:
    def countVowelStrings(self, n: int) -> int:
        s = 'aeiou'
        
        @cache
        def dp(i: int, n: int) -> int:
            if i >= len(s):
                return 0   
            if n == 0:
                return 1
            return dp(i, n - 1) + dp(i + 1, n)
        
        return dp(0, n)