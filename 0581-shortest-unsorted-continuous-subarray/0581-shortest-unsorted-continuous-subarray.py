class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        isSame = [a == b for a, b in zip(nums, sorted(nums))]
        
        if all(isSame):
            return 0
        
        n = len(isSame)
        
        l, r = 0, n - 1
        
        for i in range(n):
            if not isSame[i]:
                l = i
                break
                
        for i in range(n - 1, -1, -1):
            if not isSame[i]:
                r = i
                break
        
        return r - l + 1