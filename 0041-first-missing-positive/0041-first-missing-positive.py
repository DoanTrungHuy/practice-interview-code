class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = list(set(nums))
        step = 1
        
        nums.sort()
        
        for num in nums:
            if num <= 0:
                continue
            if num != step:
                return step
            step += 1
            
        return step