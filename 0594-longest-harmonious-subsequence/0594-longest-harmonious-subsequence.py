class Solution:
    def findLHS(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = 0
        
        for num in nums:
            if num + 1 in cnt:
                ans = max(ans, cnt[num] + cnt[num + 1])
                
        return ans