class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        dp, lis = [10**8] * (len(obstacles)), []
        
        for obstacle in obstacles:
            index = bisect_right(dp, obstacle)
            lis.append(index + 1)
            dp[index] = obstacle
        
        return lis