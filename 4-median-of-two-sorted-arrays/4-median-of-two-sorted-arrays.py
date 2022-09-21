class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums3 = nums1 + nums2
        nums3.sort()
        n = len(nums3)
        m = n // 2
        
        if n % 2 == 0:
           return (nums3[m - 1] + nums3[m]) / 2
    
        return nums3[m]