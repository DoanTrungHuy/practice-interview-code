class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            if nums1 == nums2:
                return 0
            else:
                return -1
            
        up, down = 0, 0
        
        for num1, num2 in zip(nums1, nums2):
            diff = abs(num1 - num2)
            
            if diff % k != 0:
                return -1
            
            if num1 > num2:
                up += diff // k
            else:
                down += diff // k
            
        return up if up == down else -1