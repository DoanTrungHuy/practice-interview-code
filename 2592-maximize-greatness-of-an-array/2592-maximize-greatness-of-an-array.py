class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        heap = []
        
        for num in nums:
            heappush(heap, num)
            
        nums.sort()
        cnt = 0
        
        for num in nums:
            while heap and heap[0] <= num:
                heappop(heap)
            if not heap:
                break
            cnt += 1
            heappop(heap)
                
        return cnt