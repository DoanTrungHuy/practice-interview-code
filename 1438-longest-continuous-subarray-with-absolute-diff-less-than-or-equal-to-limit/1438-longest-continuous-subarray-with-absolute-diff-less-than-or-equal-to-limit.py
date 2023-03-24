class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        dqMin = deque()
        dqMax = deque()
        l = 0
        ans = 0
        n = len(nums)
        
        for r in range(n):
            while dqMin and nums[dqMin[-1]] >= nums[r]:
                dqMin.pop()
                
            while dqMax and nums[dqMax[-1]] <= nums[r]:
                dqMax.pop()
                
            dqMin.append(r)
            dqMax.append(r)
            
            while nums[dqMax[0]] - nums[dqMin[0]] > limit:
                if dqMax[0] == l:
                    dqMax.popleft()
                if dqMin[0] == l:
                    dqMin.popleft()
                l += 1
            
            ans = max(ans, r - l + 1)
            
        return ans