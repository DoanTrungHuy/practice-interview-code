class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        
        @cache
        def dp(i):
            if i == n:
                return 0
            maxi = 0
            size = 0
            answ = 0
            for j in range(i, min(i + k, n)):
                size += 1
                maxi = max(maxi, arr[j])
                answ = max(answ, maxi*size + dp(j + 1))
            return answ
        
        return dp(0)