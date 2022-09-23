class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        ans = [0] * n
        i, j = 0, n - 1
        
        for p in range(n - 1, -1, -1):
            if abs(nums[i]) > abs(nums[j]):
                ans[p] = nums[i] * nums[i]
                i += 1
            else:
                ans[p] = nums[j] * nums[j]
                j -= 1
        
        return ans
                