class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n < 2:
            return 0
        
        minVal, maxVal = min(nums), max(nums)
        
        if minVal == maxVal:
            return 0
        
        sizeBucket = ceil((maxVal - minVal) / (n - 1))
        buckets = [[math.inf, -math.inf] for _ in range(n)]
        
        for i in range(n):
            j = (nums[i] - minVal) // sizeBucket
            buckets[j][0] = min(buckets[j][0], nums[i])
            buckets[j][1] = max(buckets[j][1], nums[i])
                
        prev = buckets[0][1]
        answ = sizeBucket
                
        for i in range(1, n):
            if buckets[i][0] == math.inf:
                continue
            answ = max(answ, buckets[i][0] - prev)
            prev = buckets[i][1]
        
        return answ