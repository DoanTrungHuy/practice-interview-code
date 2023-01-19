class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        total = 0
        hashMap = defaultdict(int)
        hashMap[0] = 1
        
        for num in nums:
            total = (total + num) % k
            hashMap[total] += 1
            
        ans = 0
        
        for c in hashMap.values():
            ans += c * (c - 1) // 2
            
        return ans