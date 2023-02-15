class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = num[::-1]
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

        return num[::-1]