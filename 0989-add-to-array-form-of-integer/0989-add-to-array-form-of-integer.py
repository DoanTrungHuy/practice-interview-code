class Solution:
    def reverseStr(self, num: List[int]) -> None:
        l = 0
        r = len(num) - 1
        
        while l < r:
            num[l], num[r] = num[r], num[l]
            l += 1
            r -= 1
        
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        self.reverseStr(num)
        n = len(num)
        carry = 0
        
        for i in range(n):
            carry += k % 10
            num[i] += carry
            carry = num[i] // 10
            num[i] %= 10
            k //= 10
            
        k += carry
        
        while k > 0:
            num.append(k % 10)
            k //= 10
            
        self.reverseStr(num)

        return num