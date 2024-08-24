class Solution:
    def nearestPalindromic(self, n: str) -> str:
        n = int(n)
        
        def convertNum(num):
            s = list(str(num))
            l = (len(s) - 1) // 2
            r = (len(s)) // 2
            
            while l >= 0:
                s[r] = s[l]
                l -= 1
                r += 1
                
            s = ''.join(s)
                
            return int(s)
        
        left = 0
        right = 10**18
        min_nump = 0
        
        while left <= right:
            mid = (left + right) // 2
            mid_pl = convertNum(mid)
            
            if mid_pl < n:
                min_nump = mid_pl
                left = mid + 1
            else:
                right = mid - 1
                
        left = 0
        right = 10**18
        max_nump = 0
        
        while left <= right:
            mid = (left + right) // 2
            mid_pl = convertNum(mid)
            
            if mid_pl > n:
                max_nump = mid_pl
                right = mid - 1
            else:
                left = mid + 1
                
        if max_nump - n >= n - min_nump:
            return str(min_nump)
        
        return str(max_nump)