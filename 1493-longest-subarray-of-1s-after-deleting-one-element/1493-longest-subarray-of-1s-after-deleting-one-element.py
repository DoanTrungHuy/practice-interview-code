class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        j = 0
        cntZero = 0
        ans = 0
        
        for i in range(n):
            if nums[i] == 0:
                cntZero += 1
            while cntZero > 1:
                if nums[j] == 0:
                    cntZero -= 1
                j += 1
            ans = max(ans, i - j)
            
        return ans