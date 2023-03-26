class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        m = len(queries)
        
        nums.sort()
        prefSum = [nums[0]]
        
        for i in range(1, n):
            prefSum.append(prefSum[-1] + nums[i])
            
        ans = []
            
        for q in queries:
            if nums[0] > q:
                ans.append(prefSum[n - 1] - n * q)
            elif nums[n - 1] < q:
                ans.append(n * q - prefSum[n - 1])
            else:
                l = bisect_right(nums, q) - 1
                        
                ans.append((l + 1) * q - prefSum[l] + (prefSum[n - 1] - prefSum[l]) - (n - 1 - l) * q)
            
        return ans