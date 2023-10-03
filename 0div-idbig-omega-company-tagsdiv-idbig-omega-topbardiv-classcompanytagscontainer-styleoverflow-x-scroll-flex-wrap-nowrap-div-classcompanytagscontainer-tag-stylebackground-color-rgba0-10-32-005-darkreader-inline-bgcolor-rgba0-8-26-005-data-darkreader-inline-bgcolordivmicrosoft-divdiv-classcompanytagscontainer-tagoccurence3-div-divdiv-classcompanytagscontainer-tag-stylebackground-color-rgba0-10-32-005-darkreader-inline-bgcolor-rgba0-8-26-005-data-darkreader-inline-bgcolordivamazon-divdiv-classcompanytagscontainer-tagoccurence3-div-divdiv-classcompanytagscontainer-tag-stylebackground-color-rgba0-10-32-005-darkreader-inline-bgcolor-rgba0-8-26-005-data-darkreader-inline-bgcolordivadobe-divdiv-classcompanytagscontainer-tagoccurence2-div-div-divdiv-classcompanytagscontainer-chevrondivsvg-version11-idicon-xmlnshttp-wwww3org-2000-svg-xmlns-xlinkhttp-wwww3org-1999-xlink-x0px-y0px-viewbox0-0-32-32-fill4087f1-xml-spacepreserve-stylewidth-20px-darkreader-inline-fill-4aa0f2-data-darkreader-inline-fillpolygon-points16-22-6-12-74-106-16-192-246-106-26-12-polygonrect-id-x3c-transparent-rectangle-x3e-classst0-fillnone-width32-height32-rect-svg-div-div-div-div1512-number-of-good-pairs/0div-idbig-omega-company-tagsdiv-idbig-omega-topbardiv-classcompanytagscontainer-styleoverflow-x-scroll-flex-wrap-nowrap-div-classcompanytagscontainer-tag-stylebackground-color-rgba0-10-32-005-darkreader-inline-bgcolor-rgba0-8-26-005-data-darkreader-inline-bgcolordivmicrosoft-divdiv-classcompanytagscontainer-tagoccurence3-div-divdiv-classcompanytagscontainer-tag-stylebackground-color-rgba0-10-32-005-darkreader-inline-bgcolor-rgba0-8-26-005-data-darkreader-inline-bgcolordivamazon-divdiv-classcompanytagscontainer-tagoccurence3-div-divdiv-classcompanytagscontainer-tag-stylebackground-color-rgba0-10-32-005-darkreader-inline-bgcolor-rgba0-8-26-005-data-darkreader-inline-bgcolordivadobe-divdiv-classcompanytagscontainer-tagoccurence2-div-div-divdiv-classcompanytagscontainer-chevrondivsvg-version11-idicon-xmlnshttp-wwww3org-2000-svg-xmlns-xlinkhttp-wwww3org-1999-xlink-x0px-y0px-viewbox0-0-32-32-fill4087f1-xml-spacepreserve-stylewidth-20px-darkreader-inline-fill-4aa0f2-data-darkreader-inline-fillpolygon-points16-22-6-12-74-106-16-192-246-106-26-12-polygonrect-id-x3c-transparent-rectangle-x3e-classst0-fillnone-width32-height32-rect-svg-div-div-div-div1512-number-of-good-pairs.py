class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        hashMap = defaultdict(int)
        res = 0
        
        for num in nums:
            res += hashMap[num]
            hashMap[num] += 1
        
        return res