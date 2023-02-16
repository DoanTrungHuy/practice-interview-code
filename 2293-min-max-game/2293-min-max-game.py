class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        
        while n > 1:
            for i in range(n // 2):
                if i % 2 == 0:
                    nums[i] = min(nums[2*i], nums[2*i + 1])
                else:
                    nums[i] = max(nums[2*i], nums[2*i + 1])
            n //= 2
            
        return nums[0]