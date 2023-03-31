class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        h = defaultdict(int)
        
        for i in range(n):
            h[nums[i] & nums[i]] += 1
            for j in range(i + 1, n):
                h[nums[i] & nums[j]] += 2
                
        ans = 0
        
        for k in range(n):
            for numIJ, cnt in h.items():
                if nums[k] & numIJ:
                    continue
                ans += cnt
                
        return ans