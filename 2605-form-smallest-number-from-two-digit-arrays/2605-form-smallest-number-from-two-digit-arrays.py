class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:        
        nums1 = set(nums1)
        nums2 = set(nums2)
        
        duplicateTwoSet = nums1 & nums2
        
        if duplicateTwoSet:
            return min(duplicateTwoSet)
        
        min1 = min(nums1)
        min2 = min(nums2)
        
        return min(min1, min2) * 10 + max(min1, min2)