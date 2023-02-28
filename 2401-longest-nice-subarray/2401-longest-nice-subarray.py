class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        subArray = 0
        j = 0
        n = len(nums)
        ans = 0
        
        for i in range(n):
            while subArray & nums[i] > 0:
                subArray ^= nums[j]
                j += 1
            ans = max(ans, i - j + 1)
            subArray |= nums[i]
            
        return ans