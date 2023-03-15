class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        n, m = len(nums1), len(nums2)
        heap = [(nums1[0] + nums2[0], 0, 0)]
        ans = []
        
        while len(heap) and len(ans) < k:
            _, i, j = heappop(heap)
            ans.append([nums1[i], nums2[j]])
            
            if i < n and j + 1 < m:
                heappush(heap, (nums1[i] + nums2[j + 1], i, j + 1))
                
            if j == 0 and i + 1 < n and j < m:
                heappush(heap, (nums1[i + 1] + nums2[j], i + 1, j))
                
        return ans