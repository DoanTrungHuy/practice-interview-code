class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        j = 0
        unique = set()
        total = 0
        ans = 0
        
        for i in range(n):
            while j < n and len(unique) > 0 and nums[i] in unique:
                unique.discard(nums[j])
                total -= nums[j]
                j += 1
                
            total += nums[i]
            unique.add(nums[i])            
                
            if k == len(unique):
                ans = max(ans, total)
                total -= nums[j]
                unique.discard(nums[j])
                j += 1
                
        return ans