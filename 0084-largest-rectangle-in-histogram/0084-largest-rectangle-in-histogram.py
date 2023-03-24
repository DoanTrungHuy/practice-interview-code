class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        n = len(heights)
        ans = 0
        
        for i in range(n):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                ans = max(ans, heights[stack.pop()] * (i - stack[-1] - 1))
            stack.append(i)
            
        while stack[-1] != -1:
            ans = max(ans, heights[stack.pop()] * (n - stack[-1] - 1))
        
        return ans