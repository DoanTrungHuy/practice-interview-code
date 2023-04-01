class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:        
        min1 = min(nums1)
        min2 = min(nums2)
        
        minOneDigit = inf
        
        for d in nums1:
            if d in nums2:
                minOneDigit = min(minOneDigit, d)
                
        if minOneDigit != inf:
            return minOneDigit
        
        return min(min1, min2) * 10 + max(min1, min2)