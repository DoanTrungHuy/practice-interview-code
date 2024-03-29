class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        stack = []
        prefMinIndex = [-1] * n
        
        for i in range(n):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            if stack:
                prefMinIndex[i] = stack[-1]
            stack.append(i)
            
        stack = []
        suffMinIndex = [n] * n
        
        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            if stack:
                suffMinIndex[i] = stack[-1]
            stack.append(i)
            
        ans = 0
            
        for i in range(n):
            l = prefMinIndex[i] + 1
            r = suffMinIndex[i] - 1
            
            if l <= k <= r:
                ans = max(ans, nums[i] * (r - l + 1))
        
        return ans