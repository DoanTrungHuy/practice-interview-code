class Solution:
    def kthCharacter(self, k: int, ops: List[int]) -> str:
        n = len(ops)
        ans = 'a'
        real_size = (1 << n)
        
        for i in range(n - 1, -1, -1):
            real_size //= 2
            
            if k > real_size:
                if ops[i]:
                    if ans == 'z':
                        ans = 'a'
                    else:
                        ans = chr(ord(ans) + 1)
                        
                k -= real_size
                
        return ans