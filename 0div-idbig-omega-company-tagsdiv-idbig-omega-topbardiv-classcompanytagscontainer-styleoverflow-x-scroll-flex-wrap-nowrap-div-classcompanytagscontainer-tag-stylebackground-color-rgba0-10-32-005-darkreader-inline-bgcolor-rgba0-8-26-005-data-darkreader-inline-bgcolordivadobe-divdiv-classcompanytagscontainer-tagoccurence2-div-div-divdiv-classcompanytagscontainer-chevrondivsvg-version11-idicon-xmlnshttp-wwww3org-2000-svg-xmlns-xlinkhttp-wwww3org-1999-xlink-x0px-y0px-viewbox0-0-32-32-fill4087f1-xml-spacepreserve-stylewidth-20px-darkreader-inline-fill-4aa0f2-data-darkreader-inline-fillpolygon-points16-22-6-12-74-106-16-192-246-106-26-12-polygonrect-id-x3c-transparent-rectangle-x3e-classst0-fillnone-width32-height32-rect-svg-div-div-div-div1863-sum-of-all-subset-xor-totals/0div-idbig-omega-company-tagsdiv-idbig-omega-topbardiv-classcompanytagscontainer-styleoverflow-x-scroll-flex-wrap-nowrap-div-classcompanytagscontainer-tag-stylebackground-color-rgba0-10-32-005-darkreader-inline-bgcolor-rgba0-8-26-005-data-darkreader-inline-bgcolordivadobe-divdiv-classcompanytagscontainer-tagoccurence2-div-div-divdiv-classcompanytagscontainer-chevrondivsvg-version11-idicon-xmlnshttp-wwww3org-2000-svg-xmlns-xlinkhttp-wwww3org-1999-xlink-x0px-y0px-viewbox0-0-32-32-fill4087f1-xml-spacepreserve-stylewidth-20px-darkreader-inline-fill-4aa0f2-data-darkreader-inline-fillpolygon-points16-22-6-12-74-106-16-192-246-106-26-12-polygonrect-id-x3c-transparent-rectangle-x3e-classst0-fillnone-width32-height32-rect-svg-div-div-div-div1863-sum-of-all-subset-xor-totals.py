class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        
        for mask in range(1 << n):
            total = 0
            for i in range(n):
                if (mask >> i) & 1:
                    total ^= nums[i]
            res += total
            
        return res