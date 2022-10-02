class Solution:
    def __init__(self):
        self.ans = []
        
    def backTracking(self, nums, k, path):
        if len(path) == k:
            self.ans.append(path)
            return
        for i in range(len(nums)):
            self.backTracking(nums[i + 1:], k, path + [nums[i]])
            
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.backTracking(list(range(1, n + 1)), k, []);
        return self.ans