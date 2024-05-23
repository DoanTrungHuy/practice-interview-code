class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        self.ans = 0
        
        def dfs(i, cnt):
            if i == n:
                self.ans += 1
                return
            if cnt[nums[i] - k] == 0:
                cnt[nums[i]] += 1
                dfs(i + 1, cnt)
                cnt[nums[i]] -= 1
            dfs(i + 1, cnt)
            
        dfs(0, defaultdict(int))
        
        return self.ans - 1