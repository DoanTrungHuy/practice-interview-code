class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        line = defaultdict(int)
        repeat = defaultdict(int)
        
        n = len(nums)
        m = n // 2
        
        for i in range(m):
            a = nums[i]
            b = nums[n - 1 - i]
            
            left, right = min(a, b) + 1, max(a, b) + limit
            
            line[left] += 1
            line[right + 1] -= 1
            repeat[a + b] += 1
            
        LIMIT_REPEAT = max(repeat)
        ans = float(inf)
            
        for s in range(2, LIMIT_REPEAT + 1):
            line[s] += line[s - 1]
            ans = min(ans, line[s] + (m - line[s])*2  - repeat[s])
            
        return ans