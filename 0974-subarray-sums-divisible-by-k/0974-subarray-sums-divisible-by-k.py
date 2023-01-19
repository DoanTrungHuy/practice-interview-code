class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        total = 0
        hashMap = defaultdict(int)
        hashMap[0] = 1
        ans = 0
        
        for num in nums:
            total = (total + num) % k
            ans += hashMap[total]
            hashMap[total] += 1
            
        return ans