class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        cnt_zero = nums.count(0)
        n = len(nums)
        
        if cnt_zero > 1:
            return [0 for _ in range(n)]
        
        pro = 1
        
        for num in nums:
            if num:
                pro *= num
        
        for i in range(n):
            if cnt_zero == 0:
                nums[i] = pro // nums[i]
            else:
                nums[i] = 0 if nums[i] else pro
        
        return nums