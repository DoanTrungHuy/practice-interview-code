class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        h1, h2 = [], []
        
        nums.sort()
        n = len(nums)
        
        for i in range(n // 2):
            heappush(h1, -nums[i])
        
        for i in range(n // 2, n):
            heappush(h2, -nums[i])
            
        ans = 0
        
        while h1 and h2:
            while h1 and -h1[0] * 2 > -h2[0]:
                heappop(h1)
            if h1:
                ans += 2
                heappop(h1)
            heappop(h2)
            
        return ans