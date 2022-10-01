class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        xor1, xor2 = 0, 0
        
        for i in range(n):
            xor1 ^= nums1[i]
            
        for i in range(m):
            xor2 ^= nums2[i]
        
        return (m % 2 * xor1) ^ (n % 2 * xor2)