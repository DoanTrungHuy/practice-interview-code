class Solution:
    def compress(self, chars: List[str]) -> int:
        contains = groupby(''.join(chars))
        ans = 0
        tmp = []
        
        for u, v in contains:
            v = len(list(v))
            if v != 1:
                ans += v + 1
                tmp.append(u)
                for c in str(v):
                    tmp.append(c)
            else:
                tmp.append(u)
                ans += v
                
        chars[:] = tmp
        
        return ans