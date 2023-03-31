class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        h = defaultdict(int)
        
        for i in range(n):
            for j in range(n):
                h[nums[i] & nums[j]] += 1
                
        ans = 0
        
        for k in range(n):
            for numIJ, cnt in h.items():
                if nums[k] & numIJ:
                    continue
                ans += cnt
                
        return ans