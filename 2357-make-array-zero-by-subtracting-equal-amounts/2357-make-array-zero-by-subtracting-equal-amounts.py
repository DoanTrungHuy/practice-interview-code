class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        p = set()
        
        for num in nums:
            if num > 0:
                p.add(num)
                
        return len(p)