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
                cnt = 0
                for char in arr[j]:
                    if char in seen:
                        flag = False
                        break
                    seen.add(char)
                    cnt += 1
                if not flag:
                    break
                size += cnt
  
            if size > ans:
                ans = size
                
        return ans