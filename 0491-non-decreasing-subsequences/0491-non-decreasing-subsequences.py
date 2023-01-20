class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = set()
        
        def backTracking(i: int, path: List[int]) -> None:
            if len(path) >= 2:
                ans.add(tuple(path))
            if i >= n:
                return
            for j in range(i, n):
                if not path or nums[j] >= path[-1]:
                    backTracking(j + 1, path + [nums[j]])
                
        backTracking(0, [])
                
        return ans