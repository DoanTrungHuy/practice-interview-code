class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums1)
        ans = []
        
        for num in nums2:
            if cnt[num] > 0:
                ans += [num]
                cnt[num] -= 1
                
        return ans