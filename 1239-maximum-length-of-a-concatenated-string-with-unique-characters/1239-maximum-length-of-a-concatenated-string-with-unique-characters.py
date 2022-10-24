class Solution:
    def maxLength(self, arr: List[str]) -> int:
        n = len(arr)
        ans = 0
        
        for i in range(1 << n):
            seen = set()
            flag = True
            size = 0
            
            for j in range(n):
                if (i >> j) & 1 == 0:
                    continue
                for char in arr[j]:
                    if char in seen:
                        flag = False
                        break
                    seen.add(char)
                if not flag:
                    break
                size += len(arr[j])
  
            if size > ans:
                ans = size
                
        return ans