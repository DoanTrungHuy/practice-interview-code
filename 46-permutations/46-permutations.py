class Solution:      
    def backTracking(self, nums, path, n, res, visited):
        if len(path) == n:
            res.append(path)
            return
        
        for i in range(n):
            if not visited[i]:
                visited[i] = True
                self.backTracking(nums, path + [nums[i]], n, res, visited)
                visited[i] = False
        
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        visited = [False] * n
        self.backTracking(nums, [], n, res, visited)
        return res