class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        
        for i in range(1, n):
            if nums[i - 1] == nums[i]:
                return nums[i]
            
        return -1