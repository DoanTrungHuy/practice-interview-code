class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        
        @cache
        def dp(i: int) -> int:
            if i >= n - 1:
                return 0
            minJump = 10001
            for j in range(1, nums[i] + 1):
                minJump = min(minJump, 1 + dp(i + j))
            return minJump
            
        return dp(0)