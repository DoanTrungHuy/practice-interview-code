class Solution:
    def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
        if nums1 == nums2:
            return 0
        
        target = []
        total = 0
        
        for num1, num2 in zip(nums1, nums2):
            diff = abs(num1 - num2)
            total += diff
            target.append(diff)
        
        nums1.sort()
        ans = total
        n = len(nums1)
        
        for num, diff in zip(nums2, target):
            idx = bisect_left(nums1, num)
            if idx > 0:
                ans = min(ans, total - diff + abs(nums1[idx - 1] - num))
            if idx < n:
                ans = min(ans, total - diff + abs(nums1[idx] - num))
        
        return ans % (10**9 + 7)