class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        j = 0
        n = len(nums)
        
        for i in range(n):
            if nums[i] % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
                
        return nums