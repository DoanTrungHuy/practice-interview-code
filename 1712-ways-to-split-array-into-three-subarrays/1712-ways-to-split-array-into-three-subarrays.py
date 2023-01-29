class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        prefSum = [0]
        
        for num in nums:
            prefSum.append(prefSum[-1] + num)
            
        n = len(prefSum)
        ans = 0
        mod = 10**9 + 7
        
        for i in range(1, n):
            j = bisect_left(prefSum, 2 * prefSum[i])
            k = bisect_right(prefSum, (prefSum[-1] + prefSum[i]) // 2)
            ans = (ans + max(0, min(n - 1, k) - max(i + 1, j))) % mod
            
        return ans