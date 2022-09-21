class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = 0
        
        for i in range(n - 1):
            for j in range(i + 1, n):
                if abs(nums[i] - nums[j]) == k:
                    cnt += 1
                    
        return cnt