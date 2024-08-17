class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        c = [1]*n
        
        for i in range(1, n):
            if nums[i] - nums[i - 1] == 1:
                c[i] += c[i - 1]
        
        ans = []
        
        for i in range(k - 1, n):
            if c[i] >= k:
                ans.append(nums[i])
            else:
                ans.append(-1)
                
        return ans