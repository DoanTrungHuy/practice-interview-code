class Solution:
    def largestPalindrome(self, n: int, k: int) -> str:
        self.ans = [0 for _ in range(n)]
        
        p = [1]*(n + 1)
        
        for i in range(1, n + 1):
            p[i] = (p[i - 1]*10) % k
        
        @lru_cache(None)
        def dp(i, r):
            if i == (n // 2 + (n&1)):
                return r == 0
            
            for d in range(9, 0, -1):
                self.ans[i] = chr(d + ord('0'))
                self.ans[n - i - 1] = chr(d + ord('0'))
                
                if i != n - i - 1:
                    nr = (r + d*p[i] + d*p[n - i - 1]) % k
                else:
                    nr = (r + d*p[i]) % k
                
                if dp(i + 1, nr):
                    return True
                
            return False
                
        dp(0, 0)
        return ''.join(self.ans)