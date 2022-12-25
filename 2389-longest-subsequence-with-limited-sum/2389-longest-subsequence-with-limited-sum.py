class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        
        for i in range(1, n):
            nums[i] += nums[i - 1]
            
        ans = []
        
        for q in queries:
            ans.append(bisect_right(nums, q))
            
        return ans