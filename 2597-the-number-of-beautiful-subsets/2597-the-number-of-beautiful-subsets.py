class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        self.ans = 0
        
        def dfs(i, cnt, item):
            if i == n:
                if item > 0:
                    self.ans += 1
                return
            if cnt[nums[i] - k] == 0:
                cnt[nums[i]] += 1
                dfs(i + 1, cnt, item + 1)
                cnt[nums[i]] -= 1
            dfs(i + 1, cnt, item + 1)
            
        dfs(0, defaultdict(int), 0)
        
        return self.ans - 1