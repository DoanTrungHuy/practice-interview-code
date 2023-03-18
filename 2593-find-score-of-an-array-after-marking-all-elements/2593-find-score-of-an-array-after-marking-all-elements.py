class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        
        heap = []
        
        for i, num in enumerate(nums):
            heappush(heap, (num, i))
            
        visited = set()
        
        n = len(nums)
            
        for i, num in enumerate(nums):                
            get = heappop(heap)
            if get[1] not in visited:
                score += get[0]
                visited.add(get[1])
                if get[1] + 1 < n:
                    visited.add(get[1] + 1)
                if get[1] - 1 >= 0:
                    visited.add(get[1] - 1)
        
        return score