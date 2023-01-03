class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n = len(cookies)
        flag = [0] * k
        
        def backTracking(i, minDiff):
            if i == n:
                return max(flag)
            for j in range(k):
                flag[j] += cookies[i]
                minDiff = min(minDiff, backTracking(i + 1, minDiff))
                flag[j] -= cookies[i]
                if not flag[j]: break
            return minDiff
                
        return backTracking(0, inf)