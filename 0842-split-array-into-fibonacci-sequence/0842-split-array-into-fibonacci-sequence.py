class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:
        n = len(num)
        self.path = []
        MAX_INT = 2**31
        
        def dfs(i, f1, f2, size):
            if i == n:
                return size > 2
            s = 0
            for j in range(i, n):
                if num[i] == '0' and j > i:
                    break
                s = s*10 + ord(num[j]) - ord('0')
                if s > MAX_INT:
                    break                
                if size < 2 or f1 + f2 == s:
                    self.path.append(s)
                    if dfs(j + 1, f2, s, size + 1):
                        return True
                    self.path.pop()
            
            return False
        
        dfs(0, 0, 0, 0)
            
        return self.path