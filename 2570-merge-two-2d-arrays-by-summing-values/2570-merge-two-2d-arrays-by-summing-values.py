class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        n = len(nums1)
        d = defaultdict(int)
        for i in range(n):
            d[nums1[i][0]] = nums1[i][1]
            
        m = len(nums2)
        for i in range(m):
            d[nums2[i][0]] += nums2[i][1]
            
        ans = []
        
        for u, v in d.items():
            ans.append([u, v])
            
        return sorted(ans)