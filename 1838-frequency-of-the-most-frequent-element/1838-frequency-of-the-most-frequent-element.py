class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        j = 0
        total = 0
        
        for i in range(n):
            total += nums[i]
            while k + total < (i - j + 1) * nums[i]:
                total -= nums[j]
                j += 1
            ans = max(ans, i - j + 1)
            
        return ans