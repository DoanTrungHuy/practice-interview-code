class Solution:
    def getLucky(self, s: str, k: int) -> int:
        def get_digit_sum(num_str):
            return sum(int(digit) for digit in num_str)
        
        s = ''.join(str(ord(c) - ord('a') + 1) for c in s)
        
        while k > 0:
            s = str(get_digit_sum(s))
            k -= 1
        
        return int(s)
