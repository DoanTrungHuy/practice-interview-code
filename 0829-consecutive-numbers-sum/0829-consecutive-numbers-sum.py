class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        ans, x = 0, 1
        
        while x * (x + 1) // 2 <= n:
            if (n - x * (x + 1) // 2) % x == 0:
                ans += 1
                print(x)
            x += 1
        
        return ans