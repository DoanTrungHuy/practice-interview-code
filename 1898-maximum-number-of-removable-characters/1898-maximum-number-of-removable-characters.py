class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        # a0c0cb
        n = len(removable)
        l, r = 0, n
        ans = 0
        s = list(s)
        p = list(p)
        
        while l <= r:
            m = (l + r) // 2
            
            tmp = []
            
            for c in s:
                tmp.append(c)
            
            for i in range(m):
                tmp[removable[i]] = '$'
                
            i, j = 0, 0
            sizeS = len(s)
            sizeP = len(p)
            
            while i < sizeS and j < sizeP:
                if tmp[i] == p[j]:
                    j += 1
                i += 1
            
            if sizeP == j:
                ans = m
                l = m + 1
            else:
                r = m - 1
                
        return ans