class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        maxSub = -10**5
        maxSum = -10**5
        minSub = 10**5
        minSum = 10**5
        total = 0
        
        for num in nums:
            maxSum = max(num, maxSum + num)
            maxSub = max(maxSub, maxSum)
            minSum = min(num, minSum + num)
            minSub = min(minSub, minSum)
            total += num
            
        return max(maxSub, total - minSub) if maxSub > 0 else maxSub