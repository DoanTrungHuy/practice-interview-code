class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        
        heap = []
        
        for i, num in enumerate(nums):
            heappush(heap, (num, i))
            
        visited = set()
        
        n = len(nums)
            
        for i, num in enumerate(nums):                
            if heap:
                get = heappop(heap)
                if get not in visited:
                    score += get[0]
                    visited.add((num, get[1]))
                    if get[1] - 1 >= 0:
                        visited.add((nums[get[1] - 1], get[1] - 1))
                    if get[1] + 1 < n:
                        visited.add((nums[get[1] + 1], get[1] + 1))
        
        return score