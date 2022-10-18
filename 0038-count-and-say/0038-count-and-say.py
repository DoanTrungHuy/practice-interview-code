class Solution:
    def countAndSay(self, n: int) -> str:
        ans = '1'
        
        for i in range(n - 1):
            cnt, char = 1, ans[0]
            tmp = []
            
            for j in range(1, len(ans)):
                if char == ans[j]:
                    cnt += 1
                else:
                    tmp += str(cnt)
                    tmp += char
                    cnt, char = 1, ans[j]
            
            tmp += str(cnt)
            tmp += char
            
            ans = tmp
                    
        return ''.join(ans)