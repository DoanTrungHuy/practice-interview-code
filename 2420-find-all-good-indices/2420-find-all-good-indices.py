class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        l = [1] * n
        r = [1] * n
        
        l[n - 1] = 1        
        for i in range(n - 2, -1, -1):
            if nums[i + 1] >= nums[i]:
                l[i] = l[i + 1] + 1
        
        r[0] = 1
        for i in range(1, n):
            if nums[i - 1] >= nums[i]:
                r[i] = r[i - 1] + 1

        ans = []
        for i in range(1, n - 1):
            if l[i + 1] >= k and r[i - 1] >= k:
                ans += [i]
        
        return ans