class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        x = 0
        y = 0
        
        for num in nums:
            x += num
            y += sum(map(int, str(num)))
            
        return abs(x - y)