class Solution:
    def maxDistance(self, nums1: List[int], nums2: List[int]) -> int:
        res = i = 0
        for j, b in enumerate(nums2):
            while i < len(nums1) and nums1[i] > b:
                i += 1
            if i == len(nums1): break
            res = max(res, j - i)
        return res