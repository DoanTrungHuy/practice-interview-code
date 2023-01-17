class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        s = 0
        d = defaultdict(int)
        d[0] = 1
        cnt = 0
        
        for i in range(n):
            s += nums[i]
            cnt += d[s - k]
            d[s] += 1
                
        return cnt