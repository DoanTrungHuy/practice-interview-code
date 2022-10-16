class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        hashSet = set()
        
        for num in nums:
            hashSet.add(num)
            
        for num in nums:
            hashSet.add(int(str(num)[::-1]))
            
        return len(hashSet)