class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        j = 0
        
        for num in nums:
            if num > nums[j]:
                j += 1
        
        return j