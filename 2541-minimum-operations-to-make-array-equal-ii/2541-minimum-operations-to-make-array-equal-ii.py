class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if nums1 == nums2:
            return 0

        n = len(nums1)
        
        diff = [nums1[i] - nums2[i] for i in range(n)]
            
        if sum(diff) != 0:
            return -1
        
        ans = 0
        
        for num in diff:
            if num > 0:
                ans += num
            
        if k != 0 and ans % k == 0:
            return ans // k
        
        return -1