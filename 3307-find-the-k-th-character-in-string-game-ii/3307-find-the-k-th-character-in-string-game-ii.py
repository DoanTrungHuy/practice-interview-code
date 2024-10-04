class Solution:
    def kthCharacter(self, k: int, ops: List[int]) -> str:
        n = len(ops)
        ans = 'a'
        
        for i in range(n - 1, -1, -1):
            if k > (1 << i):
                if ops[i]:
                    if ans == 'z':
                        ans = 'a'
                    else:
                        ans = chr(ord(ans) + 1)
                        
                k -= (1 << i)
                
        return ans