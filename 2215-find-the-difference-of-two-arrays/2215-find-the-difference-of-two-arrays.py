class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        cnt = defaultdict(int)
        nums1 = set(nums1)
        nums2 = set(nums2)
        
        for num in nums1:
            cnt[num] += 1
            
        for num in nums2:
            cnt[num] += 1
            
        ans = [[] for _ in range(2)]
            
        for num in nums1:
            if cnt[num] == 1:
                ans[0].append(num)
                
        for num in nums2:
            if cnt[num] == 1:
                ans[1].append(num)
                
        return ans