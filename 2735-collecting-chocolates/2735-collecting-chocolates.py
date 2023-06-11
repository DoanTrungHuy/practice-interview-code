class Solution:
    def minCost(self, nums: List[int], x: int) -> int:
        n = len(nums)
        min_element = [num for num in nums]
        res = sum(nums)
        
        for i in range(1, n):
            total = i*x
            for j in range(n):
                min_element[j] = min(min_element[j], nums[(j + i) % n])
                total += min_element[j]
            res = min(res, total)
            
        return res