class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        res = 0
        
        for num in nums:
            res ^= num
            
        bitAt = -1
        
        for i in range(31, -1, -1):
            if (res >> i) & 1:
                bitAt = i
                break
            
        x = 0
        for num in nums:
            if (num >> bitAt) & 1:
                x ^= num
        
        return [x, res^x]