class Solution:
    def balancedStringSplit(self, s: str) -> int:
        balance, cnt = 0, 0
        
        for char in s:
            if char == 'R':
                balance += 1
            else:
                balance -= 1
                
            cnt += balance == 0
            
        return cnt