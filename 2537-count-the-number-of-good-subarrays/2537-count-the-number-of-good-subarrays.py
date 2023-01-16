class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        total = 0
        j = 0
        ans = 0
        n = len(nums)
        cnt = defaultdict(int)
        
        for i in range(n):
            total += cnt[nums[i]]
            cnt[nums[i]] += 1
            
            while j < i and total >= k:
                ans += n - i
                cnt[nums[j]] -= 1
                total -= cnt[nums[j]]
                j += 1
                
        return ans