class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        nums = sorted(list(zip(nums1, nums2)), key = lambda x: -x[1])
        heap = []
        ans = 0
        total = 0
        
        for num1, num2 in nums:
            heappush(heap, num1)
            total += num1
            
            if k < len(heap):
                total -= heappop(heap)
            
            if k == len(heap):
                ans = max(ans, total * num2)
                
        return ans