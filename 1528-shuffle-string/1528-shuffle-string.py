class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        n = len(s)
        ans = [''] * n
        
        for i in range(n):
            ans[indices[i]] = s[i]
            
        return ''.join(ans)