class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashMap = defaultdict(int)
        total = 0
        hashMap[0] = 1
        ans = 0
        
        # pref[i] - prefix[j] == k
        
        for num in nums:
            total += num
            ans += hashMap[total - k]
            hashMap[total] += 1
            
        return ans