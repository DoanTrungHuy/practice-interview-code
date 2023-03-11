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
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        heights = [0 for _ in range(m)]
        ans = 0
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
                    
            ans = max(ans, self.largestRectangleArea(heights))
            
        return ans
            